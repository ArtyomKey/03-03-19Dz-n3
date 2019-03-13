#define char_deq
#include <iostream>

class char_deque{
  private:
    char* data;
    int capacity;
    int size;
    int start;
    int end;
  public:
    char_deque(int cap);
    ~char_deque();
    void push_back(char x);
    void push_front(char x);
    char pop_back;
    char pop_front;
};


char_deque::char_deque(int cap){
  capacity = cap;
  begin = start = size = 0;
  data = new char[capacity + 1];
}

char_deque::~char_deque(){
  delete [] data;
}

void char_deque::push_back(char x){
  if(size >= capacity){
    capacity*= 2;
    char* temp = new char[capacity];
    for(int i = 0; i < size; i++){
      temp[i] = data[i];
    }
    delete [] data;
    data = temp;
  }
  if (size == 0){
    data[end] = x;
    size++;
    }else{
      if (end == capacity-1){
        end = 0; data[end] = x; size++;
      }else{
        end++; data[end] = x; size++;
        }
    }
}
void char_deque::push_front{
  if(size >= capacity){
    capacity*= 2;
    char* temp = new char[capacity];
    for(int i = 0; i < size; i++){
      temp[i] = data[i];
    }
    delete [] data;
    data = temp;
  }
  if (size == 0){
    data[start] = x;
    size++;
  }else{ 
    if (start == 0) {
      start = capacity - 1;
      data[start] = x;
      size++;
    }else{
      start--;
      data[start] = x;
      size++;
    }
  }
}

char char_deque::pop_back(){
  char x;
  if(size != 0 && (start == end)){
    x = data[end];
    size--;
    return x;
  }else{
    if(size == 0){
      return -1;
    }else{
      x = data[end];
      if(end == 0){
        end = capacity - 1;
        size--;
      }else{
        end--;
        size--;
      }
      return x;
    }
  }
}

char char_deque::pop_front(){
  char x;
  if(size != 0 && (start == end)){
    x = storage[start];
    size--; return x;
  }else{
    if(size == 0){
      return -1;
    }else{
      x = storage[start];
      if (start == capacity - 1){
      start = 0;
      size--;
      }else{
        start++;
        size--;
        }
      return x;
    }
  }
}