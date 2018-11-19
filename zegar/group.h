#pragma once
#include "mesh.h"

class Group : public Node {
private:
	std::vector<Node*> objects;
public:
	Group();
	~Group();
	void move(float, float, float);
	void rotate(float, float, float);
	void rotate(float, float, float, float, float, float);
	void draw();
	void add(Node *);
	template<typename T>
	void addAll(T t) {
		objects.push_back(t);
	}

	template<typename T, typename... Args>
	void addAll(T t, Args... args) {
		objects.push_back(t);
		addAll(args...);
	}
};
