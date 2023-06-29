import pandas as pd


class HashTable:
    def __init__(self):
        self.num_of_colls = 0
        self.count_of_record = 0
        self.count_of_connect = 0
        self.df = pd.DataFrame(columns=['key', 'value', 'name'], index=range(32))
        self.df = self.df.fillna(value='None')
        self.temp_dict = {'key':['6','qweqet','breat','gomelev','vitebsk','2','1','5','poland','chehoslovakia','vengeria','piiuyt','bnm,.//','qaz][qa]','wefwecww','wdgsehv','wvwvwc','wrwhrpqpd+','pqoi','qzfpowokvno4','owdfwjcw','vwvwwgw5y','5689876','=--09900=','lvkprybx'],
                        'value': [12,12,13,14,15,16,17,18,19,10,11,20,22,21,23,24,25,26,27,28,29,30,23,56,76],
                        'name':[1,2,3,4,5,6,7,8,9,101,102,103,104,105,106,107,108,109,'rfrv','rgv','rrh','jjh','tyjt','oiim','pmy']}

    def search_record(self, index, key):
        if key in self.df.loc[index]['key']:
            key_index = self.df.loc[index]['key'].index(key)
            self.count_of_connect += 1
            return self.df.loc[index]['value'][key_index], self.df.loc[index]['name'][key_index]

        return None

    def add_record(self, key, value, name, next_key):
        if self.df.loc[key]['key'] == 'None':
            self.df.loc[key] = [[next_key], [value], [name]]
            self.count_of_record += 1
            self.count_of_connect += 1
        else:
            self.num_of_colls += 1
            self.count_of_record += 1
            self.count_of_connect += 1
            values = self.df.loc[key]['value']
            names = self.df.loc[key]['name']
            next_keys = self.df.loc[key]['key']
            values.append(value)
            names.append(name)
            next_keys.append(next_key)
            self.df.loc[key] = [next_keys, values, names]

    def delete_record(self, key, next_key):
        self.count_of_connect += 1
        if self.df.loc[key]['key'] == 'None' or next_key not in self.df.loc[key]['key']:
            print("записи с таким ключём уже существует ")
        else:
            if len(self.df.loc[key]['key']) == 1:
                self.df.loc[key, 'key'] = 'None'
                self.df.loc[key, 'value'] = 'None'
                self.df.loc[key, 'name'] = 'None'
                self.count_of_record -= 1
            else:
                if next_key in self.df.loc[key]['key']:
                    key_index = self.df.loc[key]['key'].index(next_key)

                    self.df.loc[key]['key'].remove(self.df.loc[key]['key'][key_index])
                    self.df.loc[key]['value'].remove(self.df.loc[key]['value'][key_index])
                    self.df.loc[key]['name'].remove(self.df.loc[key]['name'][key_index])
                    self.count_of_record -= 1
                    return

    def edit_record(self, key, value, name, next_key):
        self.count_of_connect += 1
        if self.df.loc[key]['key'] == 'None' or next_key not in self.df.loc[key]['key']:
            print("записи с таким ключём не существует ")
        else:
            if next_key in self.df.loc[key]['key']:
                key_index = self.df.loc[key]['key'].index(next_key)

                self.df.loc[key]['value'][key_index] = value
                self.df.loc[key]['name'][key_index] = name

    def square_and_additive_hash(self, s):
        x = 0
        for c in s:
            x += ord(c)
        x **= 2
        temp = str(x)
        temp = temp[len(temp) // 2:]
        print(f'индекс ключа {s} = {int(temp) % 32}')
        return int(temp) % 32


hash_table = HashTable()

while True:
    try:
        choice = int(input("1)добавление записи;\n2)удаление записи;\n3)редактирование записи;\n4)просмотр записи;\n5)просмотр таблицы;\n6)сохранение таблицы;\n0)выход из программы;\n"))
    except ValueError:
        print("Вы ввели некорректное значение. Попробуйте снова.")
        continue
    match choice:
        case 1:
            #key = input("введите ключ: ")
            #value = input("введите значение: ")
            #name = input("введите имя: ")
            #index = hash_table.square_and_additive_hash(key)
            #hash_table.add_record(index, value, name, key)
            for i in range(25):
                index = hash_table.square_and_additive_hash(hash_table.temp_dict['key'][i])
                hash_table.add_record(index,hash_table.temp_dict['value'][i],hash_table.temp_dict['name'][i],hash_table.temp_dict['key'][i])
        case 2:
            key = input("введите ключ: ")
            index = hash_table.square_and_additive_hash(key)
            hash_table.delete_record(index, key)
        case 3:
            key = input("введите ключ: ")
            value = input("введите значение: ")
            name = input("введите имя: ")
            index = hash_table.square_and_additive_hash(key)
            hash_table.edit_record(index, value, name, key)
        case 4:
            key = input("введите ключ: ")
            index = hash_table.square_and_additive_hash(key)
            print(hash_table.search_record(index, key))
        case 5:
            print(hash_table.df)
        case 6:
            hash_table.df.to_csv('hash_table.csv')
        case 0:
            print(
            f"""всего коллизий: {hash_table.num_of_colls}.
                всего записей в таблице: {hash_table.count_of_record}.
                всего обращений к таблице: {hash_table.count_of_connect}
                Вероятность возникновения коллизий: {hash_table.num_of_colls/hash_table.count_of_record}.
                Среднее количество обращений к таблице во время поиска записи по ключу: {hash_table.count_of_connect/hash_table.count_of_record}."""
            )  
            break