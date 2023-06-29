import pandas as pd


def search_record(df):
    #global df
    key = input('input key: ')
    for index, row in df.iterrows():
        if row['key'] == key:
            print(f"value: {row['value']}, name: {row['name']}")
            return
    print(f"Запись с ключом {key} не найдена")

def add_record(df):
    #global df
    key = input('input key: ')
    value = input('input value: ')
    name = input('input name: ')
    new_record = pd.DataFrame({'key': [key], 'value': [value], 'name': [name]})
    df = df.append(new_record, ignore_index=True)
    return df 
def delete_record(df):
    #global df
    key = [input('input key: ')]
    df = df[df.key.isin(key) == False]
    return df

def edit_record(df):
    #global df
    key = input('input key: ')
    record_index = df[df['key'] == key].index
    if len(record_index) == 0:
        print(f"Запись с ключом {key} не найдена")
    else:
        print(f"Текущее значение: {df.loc[record_index]['value'].values[0]}, {df.loc[record_index]['name'].values[0]}")
        new_value = input('input new value: ')
        new_name = input('input new name: ')
        df.loc[record_index, ['value', 'name']] = [new_value, new_name]
    return df
        
    

if __name__ == '__main__':
    df = pd.DataFrame(columns=['key', 'value', 'name'])
    while True:
        choice = int(input(" 1)добавление записи;\n2)удаление записи;\n3)редактирование записи;\n4)просмотр записи;\n5)просмотр таблицы;\n6)сохранение таблицы;\n0)выход из программы;\n"))
        match choice:
            case 1:
                df = add_record(df)

            case 2:
                df = delete_record(df)
            
            case 3:
                df = edit_record(df)
                
            case 4:
                search_record(df)
            case 5:
                print(df)
            case 6:
                df.to_csv('records.csv', index=False)
            case 0:
                break