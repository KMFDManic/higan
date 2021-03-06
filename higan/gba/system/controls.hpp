struct Controls {
  Node::Button up;
  Node::Button down;
  Node::Button left;
  Node::Button right;
  Node::Button b;
  Node::Button a;
  Node::Button l;
  Node::Button r;
  Node::Button select;
  Node::Button start;

  //Game Boy Player
  Node::Rumble rumbleNode;

  auto load(Node::Object, Node::Object) -> void;
  auto poll() -> void;
  auto rumble(bool enable) -> void;

  bool yHold = 0;
  bool upLatch = 0;
  bool downLatch = 0;
  bool xHold = 0;
  bool leftLatch = 0;
  bool rightLatch = 0;
};

extern Controls controls;
