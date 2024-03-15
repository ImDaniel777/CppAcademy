class Integer
{
public:
    Integer();
    Integer(int value);

    Integer(const Integer& other);
    Integer &operator=(const Integer& other);
    Integer(Integer&& other);
    Integer &operator=(Integer&& other);

    int getValue()const;
    void setValue(int value);
    ~Integer();
private:
    int *_int;
};