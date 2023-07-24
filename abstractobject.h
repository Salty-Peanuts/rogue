class AbstractObject
{
    int x, y;
    char token;
 public:
    virtual ~AbstractObject() = 0;
    int getX();
    int getY();
    char getToken();
};