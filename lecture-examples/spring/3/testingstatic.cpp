class TestStatic{
public:
 static TestStatic * create() {
   TestStatic * p = new TestStatic();
   p->id = s_id++;
   return p;
 }

private:
  static int s_id; // declaration
  TestStatic();
  int id;
};

int TestStatic::s_id = 0; // initialization
