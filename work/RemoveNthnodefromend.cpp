/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RemoveNthnodefromend.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 02:21:43 by hounejja          #+#    #+#             */
/*   Updated: 2025/11/16 05:25:34 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int ft_size(ListNode *nodes)
{
	int i = 0;
	while (nodes)
	{
		nodes = nodes->next;
		i++;
	}
	return i;
}

ListNode* ft_next(ListNode* head, int n) // 1 2 3 4 5
{
	for (int i = 0; i < n; i++)
	{
		if (head->next) head = head->next;
	}
	return head;
}

ListNode* removeNthFromEnd(ListNode* head, int n)
{
	ListNode *fast = ft_next(head, n);
	ListNode* slow = head;
	while (fast)
	{
		if (!fast->next)
		{
			slow->next = slow->next->next;
			return head;
		}
		fast = fast->next;
		slow = slow->next;
	}
	return head;
}

int main()
{
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	// head->next->next = new ListNode(3);
	// head->next->next->next = new ListNode(4);
	// head->next->next->next->next = new ListNode(5);
	ListNode* curr = removeNthFromEnd(head, 2);
	while (curr)
	{
		std::cout << curr->val << '\n';
		curr = curr->next;
	}
}
