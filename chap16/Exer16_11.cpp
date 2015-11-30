template <typename elemType> class ListItem;
template <typename elemType> class List {
public:
	List<elemType>();
	List<elemType>(const List<elemType> &);
	List<elemType>& operator=(const List<elemType> &);
	~List();
	void insert(ListItem<elemType> *ptr, elemType value);
	// we may use the name of the template itself without arguments inside class
	// but we can never omit template arguments of other class templates
private:
	ListItem<elemType> *front, *end;
};