class Task {
  String name;
  bool isFinished;

  Task({
    this.name,
    this.isFinished = false,
  });

  void toggleDone() {
    isFinished = !isFinished;
  }
}
