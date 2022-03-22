```python
def sorted_intersect(first, second):
    # Your code goes here.
    temp = current = new = None
    while first and second:
        if first.data == second.data and first.data != current:
            current = first.data
            if temp is None:
                temp = Node(first.data)
                new = temp
            else:
                temp.next = Node(first.data)
                temp = temp.next
            first = first.next
            second = second.next
        else: #not equals
            if first.data > second.data : 
                second = second.next
            else: 
                first = first.next
    return new
   

 

def sorted_intersect(first, second):
    # Your code goes here.
    if first and second:
        if first.data == second.data:
            head = Node(first.data)
            node = sorted_intersect(first.next, second.next)
            if node is None: node = head
            elif node.data != head.data: 
                head.next = node
            return head
        elif first.data > second.data : 
            return sorted_intersect(first, second.next)
        else:  return sorted_intersect(first.next, second)
        return head if head else None
```
