class Node {
  #m_data;
  #m_next;
  constructor(data=0){
    this.#m_data = data;
    this.#m_next = null;
  }

  set data(d) {
    this.#m_data = d;
  }
  get data() {
    return this.#m_data;
  }

  set next(node) {
    this.#m_next = node;
  }

  get next() {
    return this.#m_next;
  }
};

class LinkedList {
  #m_head;

  constructor() {
    this.#m_head = null;
  }

  add(data=0) {
    if (!this.#m_head) {
      this.#m_head = new Node;
      this.#m_head.data = data;
      this.#m_head.next = null;
    }
    else {
      let new_node = new Node;
      new_node.data = data;
      new_node.next = null;

      let temp_node = this.#m_head;

      while(temp_node.next) {
        temp_node=temp_node.next;
      }
      temp_node.next = new_node;
    }
  }

  remove(data) {
    let temp_node = this.#m_head;

    if (this.#m_head.data == data) {
      this.#m_head = this.#m_head.next;
      temp_node = null;
    }
    else {
      let prev_node = temp_node;
      temp_node = temp_node.next;

      while(temp_node) {
        if (temp_node.data == data) {
          prev_node.next = temp_node.next;
          temp_node = null;
          break;
        }
        temp_node=temp_node.next;
        prev_node=prev_node.next;
      }
    }
  }

  reverse() {
    if (!this.#m_head)return;

    let prev_node = null;
    let next = this.#m_head;
    let next_next = null;

    while(next) {
      next_next = next.next;
      next.next = prev_node;
      prev_node = next;
      next = next_next;
    }
    this.#m_head = prev_node;
  }

  print() {
    let temp_node = this.#m_head;
    let string_stream = "";

    while(temp_node) {
      string_stream += temp_node.data.toString() + "->";
      temp_node=temp_node.next;
    }
    console.log(`${string_stream}nullptr`);
  }
};

const driver = () => {
  const list = new LinkedList;

  for(let i=0; i < 10; ++i) {
    list.add(i);
  }

  list.remove(4);
  list.reverse();

  list.print();
};

driver();