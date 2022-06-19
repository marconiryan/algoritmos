class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None
        self.last = None
        self.size = 0

    def append(self, data):
        aux = Node(data)
        if not self.head:
            self.head = aux
            self.last = aux
            self.size += 1
        else:
            self.last.next = aux
            self.last = aux
            self.size += 1

    def remove(self, data):
        aux = self.head
        while aux is not None:
            if aux.data == data:
                if aux == self.head:
                    proximo = aux.next
                    self.head = proximo
                    del aux
                    self.size -= 1
                    break
            if aux.next:
                if aux.next.data == data:
                    if aux.next == self.last:
                        del aux.next
                        aux.next = None
                        self.last = aux
                        self.size -= 1
                        break
                    else:
                        proximo = aux.next
                        aux.next = proximo.next
                        del proximo
                        self.size -= 1
                        break
            else:
                break
            aux = aux.next

    def print_data(self):
        aux = self.head
        while aux is not None:
            print(aux.data)
            aux = aux.next


lista = LinkedList()
lista.append(2)
lista.append(2)
lista.append(2)
lista.append(4)
lista.append(2)
lista.remove(4)
lista.print_data()
