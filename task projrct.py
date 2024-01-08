class TodoList:
    def __init__(self):
        self.tasks = []

    def add_task(self, task):
        self.tasks.append({"task": task, "completed": False})

    def mark_completed(self, index):
        if 0 <= index < len(self.tasks):
            self.tasks[index]["completed"] = True
        else:
            print("Invalid index.")

    def display_tasks(self):
        print("To-Do List:")
        for i, task in enumerate(self.tasks):
            status = "✓" if task["completed"] else " "
            print(f"{i + 1}. [{status}] {task['task']}")

def main():
    todo_list = TodoList()

    while True:
        print("\n1. Add task")
        print("2. Mark task as completed")
        print("3. Display tasks")
        print("4. Exit")
        choice = input("Select an option: ")

        if choice == "1":
            task = input("Enter task: ")
            todo_list.add_task(task)
        elif choice == "2":
            index = int(input("Enter task index to mark as completed: ")) - 1
            todo_list.mark_completed(index)
        elif choice == "3":
            todo_list.display_tasks()
        elif choice == "4":
            print("Exiting...")
            break
        else:
            print("Invalid choice. Please select a valid option.")

if __name__ == "__main__":
    main()
