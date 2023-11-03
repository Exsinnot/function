import PySimpleGUI as sg

listtodo = []
sg.theme('Python')

layout = [  [sg.Text('Type In To Do')],
            [sg.InputText(),sg.Button('Add')],
            [sg.Listbox(listtodo,size=(50,20),key="output"),sg.Button('Save To .txt',size=(10,3))],
            [sg.Button('Exit',size=(10,3))]]

window = sg.Window('To-Do APP', layout)
while True:
    event, values = window.read()
    if event == sg.WIN_CLOSED or event == 'Exit': 
        break
    if event == 'Save To .txt':
        with open("action_item.txt",'w') as f:
            for x in listtodo:
                f.write(x+"\n")
    if event == 'Add':
        listtodo.append(values[0])
        window['output'].update(listtodo)

window.close()