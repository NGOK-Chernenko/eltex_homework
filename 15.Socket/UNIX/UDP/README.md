# Датаграммные сокеты в домене UNIX
## Сначала **серверная** программа создает сокет и привязывает его к общеизвестному адресу. Затем она входит в бесконечный цикл, где принимает дата-граммы от клиентов, используя вызов recvfrom() , возвращает результат обратно клиенту. 
## Адрес клиента извлекается с помощью вызова recvfrom().
## Работу сервера нужно завершать через отправку от клиента сообщения "!server off".
## **Клиентская** программа создает сокет и привязывает его к адресу, чтобы сервер мог отправить свой ответ. Адрес клиента делается уникальным за счет добавления к пути идентификатора его процесса. Клиент отправлет серверу сообщение. Сделав это, он считывает ответ сервера и направляет его в стандартный вывод. 