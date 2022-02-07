![Снимок экрана от 2022-02-01 12-37-03](https://user-images.githubusercontent.com/90381005/151953628-b72f8428-80ff-4026-a52c-2faf03776b9d.png)
![Снимок экрана от 2022-02-03 10-22-26](https://user-images.githubusercontent.com/90381005/152306233-538d0fa6-c2c4-4d29-b746-bf9a279985c2.png)
![Снимок экрана от 2022-02-03 10-23-32](https://user-images.githubusercontent.com/90381005/152306278-4758298a-4214-40a7-96fc-b2ca627449cb.png)
![image](https://user-images.githubusercontent.com/90381005/152768160-4a881642-5924-4153-8429-4b75877d47f4.png)

```
#!/bin/bash
echo "type name"
read name
echo "type surname"
read surname
echo "Hello" $name ${surname}"!"

Запускаем bash example.sh
type name
Juli
type surname
Zhirnova
Hello Juli Zhirnova!

Создаем файл
touch in_file
с текстом
Juli
Zhirnova

и выводим его
bash example.sh < in_file
type name
type surname
Hello Juli Zhirnova!

Сам скрипт 1 вариант
#!/bin/bash

function CreateUser() {
 
  echo "Введите имя пользователя: "
  read username
    
  echo "Введите путь домашней директории: "
  read home_directory
  home_directory="-d ${home_directory}"
    
  useradd -s $SHELL "-m" $home_directory $username
 
  echo "Введите пароль: "
  read setPassword
  passwd $username
}

function DeleteUser() {
  echo "Введите имя пользователя для удаления: "
  read username
   
  echo
  userdel "-r" $username
}

function UserExist() {
  echo "Введите имя пользователя для проверки: "
  read username
echo
  grep $username /etc/passwd
}

function addVarEnv() {
  echo "Введите имя пользователя для проверки: "
  read username

  echo "Введите переменную окружения: "
  read envVar
  homedir=$( getent passwd "$username" | cut -d: -f6 )
  echo "export ${envVar}" >> $homedir/.bashrc
  echo "variable ${envVar} add to ${username}"
 
}

echo "ДЗ2 CIS Esports"
while :
do
  echo " Вы можете создать пользователя (1); проверить, есть ли пользователь в системе(2); удалить пользователя(3).
 Добавить переменные окружения (4).
 Что Вы хотите сделать (введите [1/2/3/4]). Для выхода нажмите любую кнопку с клавиатуры"

  read choice_of_user
 
  case $choice_of_user in
    1)
      CreateUser
      ;;
    2)
      UserExist
      ;;
    3)
      DeleteUser
      ;;
    4)
      addVarEnv
      ;;
    *)
      break
      ;;
  esac
done
```
