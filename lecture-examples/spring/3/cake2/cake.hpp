/**
 This is a typical cake, consisting of 8 slices
 */
class Cake{
public:
	Cake();    //Constructor
	~Cake();   //destructor
	bool	EatSlice();
	int		GetSlices();
protected:
	int iSlices;
private:
	bool bPlate;
};

class LongCake : public Cake{
public:
	LongCake();    // new constructor
};
