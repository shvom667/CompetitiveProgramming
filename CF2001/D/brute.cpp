#include<iostream>
#include<set>
#include<vector>
#include<cassert>

#include <algorithm>
#include <cassert>
#include <vector>


#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

constexpr int bsf_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}

int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal

}  // namespace atcoder


namespace atcoder {

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

}  // namespace atcoder

using namespace std;
using dat=pair<int,int>;
dat opmax(dat a,dat b)
{
	if(a.first!=b.first)return max(a,b);
	return a;
}
dat opmin(dat a,dat b)
{
	if(a.first!=b.first)return min(a,b);
	return a;
}
dat emax(){return make_pair(0,-1);}
dat emin(){return make_pair((int)1e9,-1);}
int N,A[3<<17];
vector<int>idx[3<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
  int T = 1;
	for(;T--;)
	{
		cin>>N;
		for(int i=1;i<=N;i++)idx[i].clear();
		for(int i=0;i<N;i++)
		{
			cin>>A[i];
			idx[A[i]].push_back(i);
		}
		set<int>L;
		for(int i=1;i<=N;i++)if(!idx[i].empty())L.insert(idx[i].back());
		vector<dat>init(N);
		for(int i=0;i<N;i++)init[i]=make_pair(A[i],i);
		atcoder::segtree<dat,opmax,emax>segmax(init);
		atcoder::segtree<dat,opmin,emin>segmin(init);
		vector<int>B;
		int pos=0;
		while(!L.empty())
		{
			int r=*L.begin()+1;
			dat t;
			if(B.size()%2==0)
			{//max
				t=segmax.prod(pos,r);
			}
			else
			{//min
				t=segmin.prod(pos,r);
			}
			assert(t.second!=-1);
			B.push_back(t.first);
			for(int id:idx[t.first])
			{
				segmax.set(id,emax());
				segmin.set(id,emin());
			}
			L.erase(idx[t.first].back());
			pos=t.second+1;
		}
		cout<<B.size()<<"\n";
		for(int i=0;i<B.size();i++)cout<<B[i]<<(i+1==B.size()?"\n":" ");
	}
}
