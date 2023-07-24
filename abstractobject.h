class AbstractObject
{
    int x, y;
    char token;
 public:
    virtual AbstractObject(int x, int y, char token) = 0;
    virtual ~AbstractObject() = 0;
    int getX();
    int getY();
    char getToken();
};