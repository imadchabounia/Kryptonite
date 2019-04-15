 /*
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
/* solution using Floyd's Cycle Detection Algorithm */
bool solveHelper(struct SinglyLinkedListNode *tortoise, struct SinglyLinkedListNode *hare) {
  if (hare == tortoise)
    return true;
  if (hare == NULL || tortoise == NULL || hare->next == NULL)
    return false;
  return solveHelper(tortoise->next, hare->next->next);
}
bool has_cycle(struct SinglyLinkedListNode *head) { return solveHelper(head->next, head->next->next);}
