import std.conv, std.functional, std.range, std.stdio, std.string;
import std.algorithm, std.array, std.bigint, std.bitmanip, std.complex, std.container, std.math, std.mathspecial, std.numeric, std.regex, std.typecons;
import core.bitop;

class EOFException : Throwable { this() { super("EOF"); } }
string[] tokens;
string readToken() { for (; tokens.empty; ) { if (stdin.eof) { throw new EOFException; } tokens = readln.split; } auto token = tokens.front; tokens.popFront; return token; }
int readInt() { return readToken.to!int; }
long readLong() { return readToken.to!long; }

string COLOR(string s = "") { return "\x1b[" ~ s ~ "m"; }

bool chmin(T)(ref T t, in T f) { if (t > f) { t = f; return true; } else { return false; } }
bool chmax(T)(ref T t, in T f) { if (t < f) { t = f; return true; } else { return false; } }

int binarySearch(alias pred, T)(in T[] as) { int lo = -1, hi = cast(int)(as.length); for (; lo + 1 < hi; ) { const mid = (lo + hi) >> 1; (unaryFun!pred(as[mid]) ? hi : lo) = mid; } return hi; }
int lowerBound(T)(in T[] as, T val) { return as.binarySearch!(a => (a >= val)); }
int upperBound(T)(in T[] as, T val) { return as.binarySearch!(a => (a > val)); }

struct ModInt(uint M_) {
  import std.conv : to;
  alias M = M_;
  uint x;
  this(ModInt a) { x = a.x; }
  this(uint x_) { x = x_ % M; }
  this(ulong x_) { x = cast(uint)(x_ % M); }
  this(int x_) { x = ((x_ %= cast(int)(M)) < 0) ? (x_ + cast(int)(M)) : x_; }
  this(long x_) { x = cast(uint)(((x_ %= cast(long)(M)) < 0) ? (x_ + cast(long)(M)) : x_); }
  ref ModInt opAssign(T)(inout(T) a) if (is(T == uint) || is(T == ulong) || is(T == int) || is(T == long)) { return this = ModInt(a); }
  ref ModInt opOpAssign(string op, T)(T a) {
    static if (is(T == ModInt)) {
      static if (op == "+") { x = ((x += a.x) >= M) ? (x - M) : x; }
      else static if (op == "-") { x = ((x -= a.x) >= M) ? (x + M) : x; }
      else static if (op == "*") { x = cast(uint)((cast(ulong)(x) * a.x) % M); }
      else static if (op == "/") { this *= a.inv(); }
      else static assert(false);
      return this;
    } else static if (op == "^^") {
      if (a < 0) return this = inv()^^(-a);
      ModInt b = this, c = 1U;
      for (long e = a; e; e >>= 1) { if (e & 1) c *= b; b *= b; }
      return this = c;
    } else {
      return mixin("this " ~ op ~ "= ModInt(a)");
    }
  }
  ModInt inv() const {
    uint a = M, b = x; int y = 0, z = 1;
    for (; b; ) { const q = a / b; const c = a - q * b; a = b; b = c; const w = y - cast(int)(q) * z; y = z; z = w; }
    assert(a == 1); return ModInt(y);
  }
  ModInt opUnary(string op)() const {
    static if (op == "+") { return this; }
    else static if (op == "-") { ModInt a; a.x = x ? (M - x) : 0U; return a; }
    else static assert(false);
  }
  ModInt opBinary(string op, T)(T a) const { return mixin("ModInt(this) " ~ op ~ "= a"); }
  ModInt opBinaryRight(string op, T)(T a) const { return mixin("ModInt(a) " ~ op ~ "= this"); }
  bool opCast(T: bool)() const { return (x != 0U); }
  string toString() const { return x.to!string; }
}

enum MO = 998244353;
alias Mint = ModInt!MO;


enum A = 26;

void main() {
  const numCases = readInt();
  foreach (caseId; 1 .. numCases + 1) {
    stderr.writefln("==== Case #%s ====", caseId);
    stderr.flush;
    
    int N = readInt;
    auto S = new string[N];
    foreach (i; 0 .. N) {
      S[i] = readToken;
    }
    S = S.sort.uniq.array;
    N = cast(int)(S.length);
    
    int L;
    foreach (i; 0 .. N) {
      chmax(L, cast(int)(S[i].length));
    }
    
    auto mask = new int[][](L, A + 1);
    foreach (i; 0 .. N) {
      foreach (x; 0 .. cast(int)(S[i].length)) {
        if (S[i][x] == '?') {
          foreach (a; 0 .. A + 1) mask[x][a] |= 1 << i;
        } else {
          mask[x][S[i][x] - 'A'] |= 1 << i;
        }
      }
    }
    
    Mint ans;
    foreach (p; 1 .. 1 << N) {
      Mint way = 1;
      Mint now = 1;
      foreach (x; 0 .. L) {
        const nonHatena = p & ~mask[x][A];
        if (!nonHatena) {
          now *= 26;
        } else {
          const i = bsf(nonHatena);
          if (x < cast(int)(S[i].length) && !(p & ~mask[x][S[i][x] - 'A'])) {
            // now *= 1
          } else {
            break;
          }
        }
        way += now;
      }
      ans -= (popcnt(p)&1?-1:+1) * way;
    }
    
    stdout.writefln("Case #%s: %s", caseId, ans);
    stdout.flush;
  }
}
