struct Foo
{

};

class Compare
{
  public:
    bool operator() (Foo a, Foo b)
    {
      return true;
    }
};

/*
 * Custom Compare For Priority Queue
 * priority_queue<Foo, vector<Foo>, Compare> pq;
 */ 


