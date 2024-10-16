import tkinter as tk
from tkinter import messagebox as mb
from  tkinter import ttk
from sql import SQL

class UI():
    def __init__(self):
        self.sql = SQL()
        self.data = self.sql.find_all()
        self.window = tk.Tk()
        self.window.title('Student Information')
        self.window.geometry('800x500')
        self.create_widgets()
        self.window.mainloop()

    def query_Window(self, submit):
        self.age_entry = None
        self.name_entry = None
        self.class_entry = None
        self.department_entry = None
        self.id_entry = None
        self.query_window = tk.Toplevel(self.window)
        self.query_window.title('Enter Information')
        self.query_window.geometry('250x200')
        id_label = ttk.Label(self.query_window, text='ID')
        id_label.place(x=1, y=15)
        self.id_entry = ttk.Entry(self.query_window)
        self.id_entry.place(x=80, y=15)
        name_label = ttk.Label(self.query_window, text='Name')
        name_label.place(x=1, y=45)
        self.name_entry = ttk.Entry(self.query_window)
        self.name_entry.place(x=80, y=45)
        age_label = ttk.Label(self.query_window, text='Age')
        age_label.place(x=1, y=75)
        self.age_entry = ttk.Entry(self.query_window)
        self.age_entry.place(x=80, y=75)
        class_label = ttk.Label(self.query_window, text='Class')
        class_label.place(x=1, y=105)
        self.class_entry = ttk.Entry(self.query_window)
        self.class_entry.place(x=80, y=105)
        department_label = ttk.Label(self.query_window, text='Department')
        department_label.place(x=1, y=135)
        self.department_entry = ttk.Entry(self.query_window)
        self.department_entry.place(x=80, y=135)
        submit_button = ttk.Button(self.query_window, text='Submit', command=submit)
        submit_button.place(x=45, y=165)
        cancel_button = ttk.Button(self.query_window, text='Cancel', command=lambda: {self.query_window.quit(), self.query_window.destroy()})
        cancel_button.place(x=135, y=165)
        self.query_window.mainloop()

    def load_data_into_tree(self):
        for i in self.tree.get_children():
            self.tree.delete(i)
        self.data = self.sql.find_all()
        NUMBER = 1
        self.data = list(self.data)
        self.data.sort(key=lambda x: x[1])
        self.data = tuple(self.data)
        for mes in self.data:
            mes = list(mes)
            mes[0] = NUMBER
            NUMBER += 1
            mes = tuple(mes)
            self.tree.insert('', 'end', values=mes)

    def update_display(self):
        self.load_data_into_tree()

    def create(self, mes):
        if self.sql.read(mes['ID']) is not None:
            mb.showerror('Error', 'ID already exists')
            return
        self.sql.create(mes)
        self.update_display()
        mb.showinfo('Success', 'Create Success')

    def delete(self, ID):
        if ID is None:
            return
        if self.sql.delete(ID):
            self.update_display()
            mb.showinfo('Success', 'Delete Success')
        else:
            mb.showerror('Error', 'ID not found')

    def update(self):
        def submit():
            self.mes = {}
            try:
                if self.id_entry.get() == '':
                    mb.showerror('Error', 'ID must be filled')
                    self.query_window.quit()
                    self.query_window.destroy()
                    self.update()
                    return
                int(self.id_entry.get())
            except ValueError:
                mb.showerror('Error', 'ID must be a number')
                self.query_window.quit()
                self.query_window.destroy()
                self.update()
                return
            else:
                if self.age_entry.get() != '':
                    try:
                        int(self.age_entry.get())
                    except ValueError:
                        mb.showerror('Error', 'Age must be a number')
                        self.query_window.quit()
                        self.query_window.destroy()
                        self.update()
                        return
                    self.mes['age'] = int(self.age_entry.get())

                if self.name_entry.get() != '':
                    self.mes['name'] = self.name_entry.get()
                if self.class_entry.get() != '':
                    self.mes['class'] = self.class_entry.get()
                if self.department_entry.get() != '':
                    self.mes['department'] = self.department_entry.get()
                self.mes['ID'] = int(self.id_entry.get())
                self.sql.update(self.mes['ID'], self.mes)
                self.update_display()
                mb.showinfo('Success', 'Update Success')
                self.query_window.quit()
                self.query_window.destroy()

        self.query_Window(submit)

    def read(self, ID):
        if ID is None:
            return
        mes = self.sql.read(ID)
        if mes is None:
            mb.showerror('Error', 'ID not found')
            return
        mb.showinfo('Information', 'ID: %d\nName: %s\nAge: %d\nClass: %s\nDepartment: %s'\
            %(mes[1], mes[2], mes[3], mes[4], mes[5]))

    def get_mes(self):
        def submit():
            self.mes = {}
            try:
                int(self.id_entry.get())
            except ValueError:
                mb.showerror('Error', 'ID must be a number')
                self.query_window.quit()
                self.query_window.destroy()
                self.get_mes()
            try:
                int(self.age_entry.get())
            except ValueError:
                mb.showerror('Error', 'Age must be a number')
                self.query_window.quit()
                self.query_window.destroy()
                self.get_mes()
            else:
                if self.sql.read(int(self.id_entry.get())) is not None:
                    mb.showerror('Error', 'ID already exists')
                    self.query_window.quit()
                    self.query_window.destroy()
                    self.get_mes()
                    return
                if self.name_entry.get() == '' or self.age_entry.get() == '' or self.class_entry.get() == '' or self.department_entry.get() == '':
                    mb.showerror('Error', 'All fields must be filled')
                    self.query_window.quit()
                    self.query_window.destroy()
                    self.get_mes()
                    return
                self.mes = {
                    'ID': int(self.id_entry.get()),
                    'name': self.name_entry.get(),
                    'age': int(self.age_entry.get()),
                    'class': self.class_entry.get(),
                    'department': self.department_entry.get()
                }
                self.query_window.quit()
                self.query_window.destroy()

        self.query_Window(submit) 
        return self.mes

    def get_id(self):
        ret = None
        def submit():
            if id_entry.get() == '':
                mb.showerror('Error', 'ID must be filled')
                get_id()
                return
            try:
                int(id_entry.get())
            except ValueError:
                mb.showerror('Error', 'ID must be a number')
                get_id()
                return
            else:
                nonlocal ret
                ret = int(id_entry.get())
            query_window.quit()
            query_window.destroy()
        
        query_window = tk.Toplevel(self.window)
        query_window.title('Enter ID')
        query_window.geometry('230x100')
        id_label = ttk.Label(query_window, text='ID')
        id_label.place(x=1, y=25)
        id_entry = ttk.Entry(query_window)
        id_entry.place(x=30, y=25)
        submit_button = ttk.Button(query_window, text='Submit', command=submit)  
        submit_button.place(x=15, y=65)
        cancel_button = ttk.Button(query_window, text='Cancel', command=lambda: {query_window.quit(), query_window.destroy()})
        cancel_button.place(x=105, y=65)
        query_window.mainloop()
        
        return ret

    def create_widgets(self):
        self.create_button()
        self.tree_frame = ttk.Frame(self.window)
        self.tree_frame.pack(side='top', fill='both', expand=True)
        columns = ('INDEX','ID', 'Name', 'Age', 'Class', 'Department')
        self.tree = ttk.Treeview(self.tree_frame, columns=columns, show='headings')
        # self.tree.pack(expand=True, fill='both')
        vscroll = ttk.Scrollbar(self.tree_frame, orient='vertical', command=self.tree.yview)
        self.tree.configure(yscrollcommand=vscroll.set)
        hscroll = ttk.Scrollbar(self.tree_frame, orient='horizontal', command=self.tree.xview)
        self.tree.configure(xscrollcommand=hscroll.set)
        self.tree.grid(row=0, column=0, sticky='nsew')
        vscroll.grid(row=0, column=1, sticky='ns')
        hscroll.grid(row=1, column=0, sticky='ew')
        self.tree_frame.grid_rowconfigure(0, weight=1)
        self.tree_frame.grid_columnconfigure(0, weight=1)
        for col in columns:
            self.tree.column(col, width=100, anchor='center')
            self.tree.heading(col, text=col)
        self.load_data_into_tree()

    def create_button(self):
        button_frame = ttk.Frame(self.window, width=800, height=25)
        Add_button = ttk.Button(button_frame, text='Add', command= lambda: {self.create(self.get_mes())})
        Add_button.place(x=1, y=1)
        Delete_button = ttk.Button(button_frame, text='Delete', command=lambda: {self.delete(self.get_id())})
        Delete_button.place(x=81, y=1)
        Update_button = ttk.Button(button_frame, text='Update', command=lambda: {self.update()})
        Update_button.place(x=161, y=1)
        Read_button = ttk.Button(button_frame, text='Search', command=lambda: {self.read(self.get_id())})
        Read_button.place(x=241, y=1)
        Exit_button = ttk.Button(button_frame, text='Exit', command=lambda: {self.window.quit, self.window.destroy()})
        Exit_button.place(x=321, y=1)
        button_frame.pack(side='top', fill='x')













