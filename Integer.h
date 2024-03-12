class Integer
{
public:
    Integer(int value);

    Integer(const Integer& other);
    Integer operator=(const Integer& other);
    Integer(Integer&& other);
    Integer operator=(Integer&& other);

    ~Integer();
private:
    int *_int;
};