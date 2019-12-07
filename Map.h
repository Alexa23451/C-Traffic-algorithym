#include <vector>
#include "Node.h"
#include <fstream>

using namespace std;

class Map
{
public:
	
	~Map() {
		delete(instance);
	}
	vector<Node> getlistOfNode();
	
	static Map* getInstance();

	void initMap();

	void showMap();

	void resetMap();

	string checkOn();
	
private:
	int numofVertex;
	int numofEdge;
	vector <Node> listofNode;
	static Map* instance;
	Map();
};
