import 'package:flutter/foundation.dart';
import 'dart:collection';
import 'package:todo_flutter/models/task.dart';

class TaskData extends ChangeNotifier {
  List<Task> tasksList = [];

  int get taskCount => tasksList.length;

  UnmodifiableListView<Task> get tasks => UnmodifiableListView(tasksList);

  void addTask(String newTaskTitle) {
    final task = Task(
      name: newTaskTitle,
    );
    tasksList.add(
      task,
    );
    notifyListeners();
  }

  void updateTask(Task task) {
    task.toggleDone();
    notifyListeners();
  }

  void deleteTask(Task task) {
    tasksList.remove(
      task,
    );
    notifyListeners();
  }
}
