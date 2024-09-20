class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class MyLinkedList:
    def __init__(self):
        self.dummy_head = ListNode()
        self.size = 0

    def get(self, index: int) -> int:         # : int 是返回类型提示（type hint），表示 val 应该是一个整数。类型提示是可选的，但它们可以帮助开发者理解代码的预期输入类型。
        if index < 0 or index >= self.size:
            return -1
        
        current = self.dummy_head.next
        for i in range(index):
            current = current.next
            
        return current.val

    def addAtHead(self, val: int) -> None:     #  -> None 是返回类型提示，表示这个方法不返回任何值。
        self.dummy_head.next = ListNode(val, self.dummy_head.next)
        self.size += 1

    def addAtTail(self, val: int) -> None:
        current = self.dummy_head
        while current.next:
            current = current.next
        current.next = ListNode(val)
        self.size += 1

    def addAtIndex(self, index: int, val: int) -> None:
        if index < 0 or index > self.size:
            return
        
        current = self.dummy_head
        for i in range(index):
            current = current.next
        current.next = ListNode(val, current.next)
        self.size += 1

    def deleteAtIndex(self, index: int) -> None:
        if index < 0 or index >= self.size:
            return
        
        current = self.dummy_head
        for i in range(index):
            current = current.next
        current.next = current.next.next
        self.size -= 1

    def printList(self) -> None:
        current = self.dummy_head
        
        while current.next:
            current = current.next
            print(current.val)

if __name__ == "__main__":
    List = MyLinkedList()
    List.addAtHead(7)
    List.addAtHead(2)
    List.addAtHead(1)
    List.addAtIndex(3,0)
    List.deleteAtIndex(2)
    List.addAtHead(6)
    List.addAtTail(4)
    List.get(4)
    List.addAtHead(4)
    List.addAtIndex(5,0)
    List.addAtHead(6)
    List.printList()