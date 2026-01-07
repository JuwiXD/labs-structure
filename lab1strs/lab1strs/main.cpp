#include "list.h"
int main() {
	Node* head1 = nullptr;
	std::fstream in("test1.txt");
	if (in.is_open())
	{
		createLikeQueue(head1, in);
		in.close();
	}
	else {
		createLikeQueue(head1);
	}
	ShowList(head1);
	removeDuplicates(head1);
	ShowList(head1);

}