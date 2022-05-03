#include "2_add_two_numbers.h"

ListNode* Solution2::addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode *head = new ListNode(0);
	ListNode* tail = head;
	int carry = 0, l1Value = 0, l2Value = 0;

	while (l1 || l2 || carry)
	{
		if (l1)
		{
			l1Value = l1->val;
			l1 = l1->next; //go to to next node

		}
		else
		{
			l1Value = 0;
		}

		if (l2)
		{
			l2Value = l2->val;
			l2 = l2->next; //go to to next node
		}
		else
		{
			l2Value = 0;
		}

		int sum = l1Value + l1Value + carry;
		tail->next = new ListNode(sum % 10); //add new node
		tail = tail->next; //go to next node
		carry = sum / 10; //
	}

	return head->next;
}

void testAddTwoNumbers()
{
	std::cout << "\ntestAddTwoNumbers" << std::endl;

}