import tkinter as tk
from tkinter import ttk,messagebox
import mysql.connector as mysql

class DatabaseApp:
    def __init__(self, root, connection_params):
        self.connection_params = connection_params
        self.root = root
        self.root.configure(bg='lightblue')

        self.menu_frame = tk.Frame(root)
        self.menu_frame.pack()

        self.name_table1 = "Экспонат"
        self.columns1 = ["ID_Экспоната","Название", "Описание", "Автор","Тип"]

        self.name_table2 = "Посетитель"
        self.columns2 = ["ID_Посетителя","Имя", "Фамилия", "Дата_рождения", "Контактная_информация"]

        self.name_table3 = "Гид"
        self.columns3 = ["ID_Гида","Имя", "Фамилия", "Специализация", "Контактная_информация"]

        self.name_table4 = "Экскурсия_"
        self.columns4 = ["ID_Экскурсии","Название","Дата_и_время_начала","Гид_ID"]

        self.name_table5 = "Билет_"
        self.columns5 = ["ID_Билета","Тип_билета", "Цена","Дата_и_время_покупки","Посетитель_ID", "Экскурсия_ID"]

        self.name_table6 = "Экскурсия_Экспонат"
        self.columns6 = ["Экскурсия_ID", "Экспонат_ID"]

        self.create_menu()

    def create_menu(self):
        self.root.geometry("600x426")
        self.root.title("MENU")

        tk.Button(self.menu_frame, text=f"Table1 - {self.name_table1}", command=lambda: self.show_table(self.name_table1, self.columns1, "1100x450"), height=4, width=35).grid(row=0, column=0)
        tk.Button(self.menu_frame, text=f"Table2 - {self.name_table2}", command=lambda: self.show_table(self.name_table2, self.columns2, "1150x450"), height=4, width=35).grid(row=1, column=0)
        tk.Button(self.menu_frame, text=f"Table3 - {self.name_table3}", command=lambda: self.show_table(self.name_table3, self.columns3, "1100x450"), height=4, width=35).grid(row=2, column=0)
        tk.Button(self.menu_frame, text=f"Table4 - {self.name_table4}", command=lambda: self.show_table(self.name_table4, self.columns4, "1100x450"), height=4, width=35).grid(row=3, column=0)
        tk.Button(self.menu_frame, text=f"Table5 - {self.name_table5}", command=lambda: self.show_table(self.name_table5, self.columns5, "1200x475"), height=4, width=35).grid(row=4, column=0)
        tk.Button(self.menu_frame, text=f"Table6 - {self.name_table6}", command=lambda: self.show_table(self.name_table6, self.columns6, "600x350" ), height=4, width=35).grid(row=5, column=0)

    def show_table(self, table_name, columns, size_window):
        table_window = tk.Toplevel(self.root)
        DatabaseTables(table_window, self.connection_params, table_name, columns, size_window)

class DatabaseTables:
    def __init__(self, root, connection_params, table_name, columns, size_window):
        self.root = root
        self.connection_params = connection_params
        self.table_name = table_name
        self.columns = columns
        self.size_window = size_window

        self.root.geometry(size_window)
        self.root.title(table_name)

        tk.Button(self.root, text="Добавить", command=self.add_data, height=2, width=15).grid(row=0, column=0)
        tk.Button(self.root, text="Удалить", command=self.delete_data, height=2, width=15).grid(row=1, column=0)
        tk.Button(self.root, text="Изменить", command=self.edit_data, height=2, width=15).grid(row=2, column=0)
        tk.Button(self.root, text="Обновить", command=self.update_table, height=2, width=15).grid(row=3, column=0)
        tk.Button(self.root, text="Искать", command=self.search_data, height=2, width=15).grid(row=4, column=0)
        tk.Button(self.root, text="Вернуться в меню", command=self.return_to_menu, height=2, width=15).grid(row=5, column=0)


        self.tree = ttk.Treeview(self.root, columns=self.columns, show="headings")
        for col in self.columns:
            self.tree.heading(col, text=col)
        self.tree.grid(row=0, column=1, rowspan=5, padx=10)

        self.load_data_from_DB()

    def load_data_from_DB(self):
        connect = mysql.connect(**self.connection_params)# Подключение к базе данных
        cursor = connect.cursor()
        
        query = f"SELECT * FROM {self.table_name}" # Запрос на выборку всех данных из таблицы
        cursor.execute(query)
        rows = cursor.fetchall()

        for row in rows:# Вставка данных в виджет Treeview
            self.tree.insert("", "end", values=row)

        cursor.close()
        connect.close()
        print("загрузка данных")

    def add_data(self):
        window = tk.Toplevel(self.root)
        window.title("Добавить данные")

        # Создаем фрейм для entry-полей
        entry_frame = tk.Frame(window)
        entry_frame.pack(padx=10, pady=10)

        # Создаем entry-поля для каждого столбца
        entry_widgets = {}
        for col in self.columns:
            label = tk.Label(entry_frame, text=col + ":")
            label.grid(row=len(entry_widgets), column=0, padx=5, pady=5, sticky=tk.W)

            entry_var = tk.StringVar()
            entry = tk.Entry(entry_frame, textvariable=entry_var)
            entry.grid(row=len(entry_widgets), column=1, padx=5, pady=5, sticky=tk.W)

            entry_widgets[col] = entry_var

        tk.Button(window, text="Сохранить", command=lambda: self.save_edit_and_add_data(entry_widgets, window, selected_item = None, flag_add_edd = "add"), height=2, width=15).pack(pady=10)
    
    def delete_data(self):
        delete_window = tk.Toplevel(self.root)
        delete_window.title("Удалить данные")
        # Создание метки для выбора столбца для удаления
        label = tk.Label(delete_window, text="Выберите столбец для удаления:")
        label.pack(pady=5)

        # Создаем выпадающий список с доступными столбцами
        column_var = tk.StringVar()
        column_var.set(self.columns[0])  #первый столбец по умолчанию
        column_menu = tk.OptionMenu(delete_window, column_var, *self.columns)
        column_menu.pack(pady=10)

        label_value = tk.Label(delete_window, text="Введите значение для удаления:")
        label_value.pack(pady=5)

        # Создание entry-поля для ввода значения
        entry_value_var = tk.StringVar()
        entry_value = tk.Entry(delete_window, textvariable=entry_value_var)
        entry_value.pack(pady=10)

        tk.Button(delete_window, text="Удалить", command=lambda: self.confirm_delete(column_var.get(), entry_value_var.get(), delete_window), height=2, width=15).pack(pady=10)
        print("удаление")

    def confirm_delete(self, column, value, delete_window):
        connect = mysql.connect(**self.connection_params)
        cursor = connect.cursor()
        try:
            query = f"DELETE FROM {self.table_name} WHERE {column} = %s"
            cursor.execute(query, (value,))
            connect.commit()

            # Обновляем отображение таблицы
            self.tree.delete(*self.tree.get_children())
            self.load_data_from_DB()
            tk.messagebox.showinfo("Успех", "Данные успешно удалены")
        except mysql.Error as err:
            tk.messagebox.showerror("Ошибка", f"Ошибка при удалении данных: {err}")
        finally:
            cursor.close()
            connect.close()
            delete_window.destroy()

    def edit_data(self):
        # Получение выбранной строки для редактирования
        selected_item = self.tree.selection()
        if not selected_item:
            tk.messagebox.showerror("Предупреждение", "Выберите строку для редактирования")
            return

        window = tk.Toplevel(self.root)
        window.title("Редактировать данные")

        entry_frame = tk.Frame(window)
        entry_frame.pack(padx=10, pady=10)

        # Создаем entry-поля для каждого столбца
        entry_widgets = {}
        for col in self.columns:
            label = tk.Label(entry_frame, text=col + ":")
            label.grid(row=len(entry_widgets), column=0, padx=5, pady=5, sticky=tk.W)

            entry_var = tk.StringVar(value=self.tree.item(selected_item, 'values')[len(entry_widgets)])
            entry = tk.Entry(entry_frame, textvariable=entry_var)
            entry.grid(row=len(entry_widgets), column=1, padx=5, pady=5, sticky=tk.W)

            entry_widgets[col] = entry_var

        tk.Button(window, text="Сохранить", command=lambda: self.save_edit_and_add_data(entry_widgets, window, selected_item, flag_add_edd = "edit"), height=2, width=15).pack(pady=10)

    def save_edit_and_add_data(self, entry_widgets, window,selected_item = None, flag_add_edd = None):
        data = [entry_widgets[col].get() for col in self.columns] # Получение данных из entry-полей
        # Проверка наличия данных во всех entry-полях
        if all(data):
            connect = mysql.connect(**self.connection_params)
            cursor = connect.cursor()
            if flag_add_edd == "add": # Запрос на добавление данных
                query = f"INSERT INTO {self.table_name} ({', '.join(self.columns)}) VALUES ({', '.join(['%s']*len(self.columns))})"
                cursor.execute(query, tuple(data))
                print("добавление")

            if flag_add_edd == "edit": # Запрос на обновление данных
                set_clause = ", ".join([f"{col} = %s" for col in self.columns])
                query = f"UPDATE {self.table_name} SET {set_clause} WHERE {self.columns[0]} = %s"
                cursor.execute(query, tuple(data + [self.tree.item(selected_item, 'values')[0]]))
                print("изменение")
            connect.commit()
            cursor.close()
            connect.close()

            # Обновляем отображение таблицы
            self.tree.delete(*self.tree.get_children())
            self.load_data_from_DB()

            window.destroy()
        else:
            tk.messagebox.showerror("Ошибка", "Заполните все поля")
        

    def search_data(self):
        search_window = tk.Toplevel(self.root)
        search_window.title("Поиск данных")

        label = tk.Label(search_window, text="Введите строку для поиска:")
        label.pack(pady=5)

        entry_var = tk.StringVar()
        entry = tk.Entry(search_window, textvariable=entry_var)
        entry.pack(pady=10)

        # Создаем выпадающий список для выбора сортировки
        sort_options = ["ASC", "DESC"]
        sort_var = tk.StringVar(search_window)
        sort_var.set(sort_options[0])  # Устанавливаем значение по умолчанию
        sort_menu = tk.OptionMenu(search_window, sort_var, *sort_options)
        sort_menu.pack(pady=10)


        # Создаем выпадающий список для выбора столбца сортировки
        column_options = self.columns  # Используем ваши столбцы как опции
        column_var = tk.StringVar(search_window)
        column_var.set(column_options[0])  # Устанавливаем значение по умолчанию
        column_menu = tk.OptionMenu(search_window, column_var, *column_options)
        column_menu.pack(pady=10)

        tk.Button(search_window, text="Искать", command=lambda: self.perform_search(entry_var.get(), sort_var.get(), column_var.get(), search_window), height=2, width=15).pack(pady=10)
    
    def perform_search(self, search_string, sort_order, sort_column, search_window):
        connect = mysql.connect(**self.connection_params)
        cursor = connect.cursor()
        query = f"SELECT * FROM {self.table_name} WHERE CONCAT({', '.join(self.columns)}) LIKE %s"
        

        # Добавляем сортировку
        if sort_order == "ASC":
            query += f" ORDER BY {sort_column} ASC"
        else:
            query += f" ORDER BY {sort_column} DESC"
      
        cursor.execute(query, (f"%{search_string}%",))
        rows = cursor.fetchall()

        self.tree.delete(*self.tree.get_children())

        for row in rows:
            self.tree.insert("", "end", values=row)

        cursor.close()
        connect.close()

        search_window.destroy()
        print("поиск")

    def update_table(self):# Обновляем отображение таблицы
        self.tree.delete(*self.tree.get_children())
        self.load_data_from_DB()
        print("обновление")
        
    def return_to_menu(self):
        print("return_to_menu")
        self.root.withdraw() # Скрыть текущее окно
        self.root.destroy()  

if __name__ == "__main__":
    connection_params = {"host": "localhost", "user": "root", "password": "1234567890-", "database": "kursov"}
    try:
        root = tk.Tk()
        app = DatabaseApp(root, connection_params)
        root.mainloop()

        print("Application closed")
    except mysql.Error as err:
        print(f"Error: {err}")
