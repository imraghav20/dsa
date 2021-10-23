
template <typename T>
class queue;

template <typename T>
class Node{
    public:
        T data;
        Node<T>* next;
        Node(T d){
            data = d;
        }
};

template <typename T>
class queue{
    Node<T>* head;
    public:
        queue(){
            head = NULL;
        }
        void push(T d){
            if(head == NULL){
                Node<T>* n = new Node<T>(d);
                head = n;
            }
            else{
                Node<T>* temp = head;
                while(temp->next!=NULL){
                    temp = temp->next;
                }
                Node<T>* n = new Node<T>(d);
                temp->next = n;
            }

        }
        void pop(){
            if(head!=NULL){
                Node<T>* temp = head;
                head=head->next;
                delete temp;
            }
        }
        T front(){
            T d = head->data;
            return d;
        }
};