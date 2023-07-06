/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void create_node(struct ListNode **head, struct ListNode **last, int r) 
{
    struct ListNode *new = NULL;
    new = (struct ListNode *)malloc(sizeof(struct ListNode));
    new->next = NULL;
    new->val = r;
    if ((*head) == NULL) 
    {
        (*head) = new;
        (*last) = new;
    } 
    else 
    {
        (*last)->next = new;
        (*last) = new;
    }
    return;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
    struct ListNode *head = NULL;
    struct ListNode *last = NULL;
    struct ListNode *tmp = NULL;
    int sum = 0;
    int rem = 0;
    while (l1 && l2) 
    {
        sum = sum + l1->val + l2->val;
        rem = sum % 10;
        sum = sum / 10;
        l1 = l1->next;
        l2 = l2->next;
        create_node(&head, &last, rem);
    }
    tmp = (l1 == NULL ? l2 : l1);
    while (tmp)
    {
        sum = sum + tmp->val;
        rem = sum % 10;
        sum = sum / 10;
        tmp = tmp->next;
        create_node(&head, &last, rem);
    }
    if (sum)
        create_node(&head, &last, sum);
    return head;
}
