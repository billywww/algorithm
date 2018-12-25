#include<stdio.h>
#include<malloc.h>
#include<math.h>

  struct ListNode {
      int val;
      struct ListNode *next;
  };

  struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    struct ListNode* l3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* p = l3;

    int i = 0;
    int k = 0;
    while(l1 && l2){
      i = l1->val + l2->val;
      p ->val = (i + k) % 10;
      if((i + k)>= 10){
        k = 1;
        if(l1->next || l2->next){
          p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
          p = p->next;
          if(l1->next && l2->next){}
          else if(l1->next){
            l2->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            l2->next->val = 0;
            l2->next->next = NULL;
          }
          else{
            l1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            l1->next->val = 0;
            l1->next->next = NULL;
          }
        }
        else{
          p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
          p = p->next;
          p->val = 1;
          p->next = NULL;
        }
      }
      else{
        k = 0;
        if(l1->next || l2->next){
          if(l1->next && l2->next){
            p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            p = p->next;
          }
        }
        else{
          p->next = NULL;
        }
      }
      l1 = l1->next;
      l2 = l2->next;
    }

    if(l1){p->next = l1;}
    if(l2){p->next = l2;}

    return l3;
  }


// struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
//
//     struct ListNode* l3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//     struct ListNode* p = l3;
//
//     long i = 0;
//     int k = 0;
//     while(l1){
//         i = i + pow(10,k)*(l1->val);
//         l1 = l1->next;
//         k++;
//     }
//
//     long j = 0;
//     k = 0;
//      while(l2){
//         j = j + pow(10,k)*(l2->val);
//         l2 = l2->next;
//         k++;
//     }
//
//     long r = i + j;
//     while(r){
//         int m = r%10;
//         p->val = m;
//         r = r/10;
//         if(r != 0){
//             p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
//             p = p->next;
//         }
//         else{
//             p->next = NULL;
//         }
//     }
//
//     return l3;
// }
