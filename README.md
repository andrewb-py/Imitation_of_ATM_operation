Надо смоделировать работу банкомата следующей конструкции.

Банкоматсостоит из следующих элементов:
пульт управления;
устройство идентификации банковской карты (номер карты + пин код);
устройство приема денег;
устройство выдачи денег;
устройство отображения состояния банкомата и состояния выполняемой операции.
Кнопки пульта управления:
цифровая клавиатура;
кнопки выполнения операции;
кнопка завершения операции.

Правила работы с банкоматом.
Банкомат готовиться к работе следующим образом:
1.Загружается   информация   относительно   зарегистрированных   карт   иимеющих на них средств.
2.Загружается заданное количество купюр для выдачи денег.
3.Выводится сообщение о готовности банкомата к работе.После готовности банкомата выполняются действия:
  приложить карту к устройству идентификации;
  распознавание карты;
  запрос, ввод и подтверждение ПИН-кода;
  выбор команды;
  вносить можно купюры кратные 100 р.;
  при внесении денег осуществляется суммирование;

Если для снятия запрошенного количества денег средств на карте или в банкомате недостаточно, сообщается о недостаточности средств.
Вносить можно купюры с достоинством 5000, 2000, 1000, 500 и 100 рублей внеограниченном количестве.
При снятии денег выдаются купюры с достоинством 5000, 2000, 1000, 500 и 100 рублей.
Снятие денег осуществляется в режиме «Выдать крупными».
Идентификация карты, нажатия на кнопки пульта управления, внесение илиснятие денег моделируется посредством клавиатурного ввода.
Ввод делится на команды и их восприятие зависит от состояния банкоматапоследовательности выдачи.

Шаблоны команд:

Identification «номер карты»
Команда выдается при состоянии банкомата «Готов к работе».
Номер картызадается четырьмя группами из 4 цифр: xxxx xxxx xxxx xxxx

PIN-code «четыре цифры»
Команда может быть выдана только после подтверждения корректности номера карты и запроса «Enter the PIN code»

Deposit money «значение купюры»
Команды могут быть выданы последовательно, тогда их значения суммируются и выдается сообщение:
The amount: «введенная сумма» «значение купюры» может равняться 5000, 2000, 1000, 500, 100. Купюры других достоинств не принимаются.
После этих команд надо ввести команду подтверждения:Deposit money to the card
После выдается сообщение:Card balance «сумма на карте»
Если введена другая команда, то банкомат внесенные купюры возвращает.

Withdraw money «сумма»
По данной команде выдаются деньги в режиме «Выдать крупными».
«сумма» должна быть кратна 100. Если денег на карте достаточно и купюр вбанкомате тоже, деньги выдаются согласно сообщению:
Take the money: 5000 * «количество купюр» rub., 2000 * «количество купюр»rub., 1000 * «количество купюр» rub., 500 * «количество купюр» rub., 100 *«количество купюр» rub.
В противном случает выдается сообщение:
The amount is not a multiple of 100, если запрошенная сумма не кратна 100.
There is not enough money on the card , если на карте недостаточно средств.
There is not enough money in the ATM», tсли в банкомате недостаточно средств или из наличных купюр нельзя собрать запрошенную сумму.

End the session
Команда завершения сеанса. Последняя не завершенная команда отменяетсяи банкомат переходит в состоянии готовности. Выдается сообщение:
Ready to work

Turn off the ATM
Команда выключения банкомата. Последняя не завершенная командаотменяется и банкомат выключается.
Эта команда всегда присутствует.

Отображение текста состояния банкомата и результата операции моделируется посредством вывода на консоли.