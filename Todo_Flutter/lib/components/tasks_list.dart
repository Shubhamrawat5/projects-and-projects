import 'package:flutter/material.dart';
import 'package:provider/provider.dart';
import 'package:todo_flutter/components/task_tile.dart';
import 'package:todo_flutter/models/task_data.dart';

class TasksList extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Consumer<TaskData>(
      builder: (context, taskData, child) {
        return ListView.builder(
          itemBuilder: (context, index) {
            final taskItem = taskData.tasks[index];
            return TaskTile(
              taskTitle: taskItem.name,
              isChecked: taskItem.isFinished,
              checkBoxCallBack: (checkBoxState) {
                taskData.updateTask(
                  taskItem,
                );
              },
              longPressCallBack: () {
                taskData.deleteTask(
                  taskItem,
                );
              },
            );
          },
          itemCount: taskData.taskCount,
        );
      },
    );
  }
}
