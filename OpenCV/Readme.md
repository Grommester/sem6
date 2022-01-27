<p>OpenCV<p>
Вопросы на защиту:
  1. Нахождение изображения на изображении: addWeighted(small, 0.6, im, 0.4, 0, im);
  2. Как записать данные в файл? o/ifstream file; and "<<"
  3. Как обработать нажатие на правую кнопки мыши if (event == EVENT_RBUTTONDOWN
  4-5. Добавьте в main вызов функции файл через if 
  if (check == "read") {
	reading("coordinat.txt", "home.png", wl, hl, wr, hr);
}
else if (check == "enter") {
	Mat image = imread("home.png");
	namedWindow("modernGoogle");
	setMouseCallback("modernGoogle", my_mouse_callback, &image);
	while (true) {
		imshow("modernGoogle", image);
		waitKey(30);
	}
}
  else if(check == "file"){
  void file()
  }
else {
	cout << "Ошибка ввода" << endl;
	waitKey(30);
