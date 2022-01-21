int main(int argc, char** argv) {

const char* traectory_file = "coordinat.txt";
double wl = 55.639799;
double hl = 37.828428;
double wr = 55.622020;
double hr = 37.873735;
Mat image = imread("kartinka.jpeg");
Mat small = imread("da.jpg");
namedWindow("modernGoogle");
Mat dst, im;


setMouseCallback("modernGoogle", my_mouse_callback, &image);
while (true) {
	imshow("modernGoogle", image);
	waitKey(30);
}
return(0);
}

void my_mouse_callback(int event, int x, int y, int flags, void* param)
{
	if (event == EVENT_LBUTTONDOWN)
	{
		Mat* plmage = (Mat*)param;
		Mat image = *plmage;
		Mat small = imread("da.jpg");
		Mat im;
		im = image(Rect(x, y, small.cols, small.rows));

		addWeighted(small, 0.6, im, 0.4, 0, im);
		std::ofstream file;
		file.open("test1.txt", ios_base::app);
		unsigned long milliseconds_since_epoch = chrono::system_clock::now().time_since_epoch() / chrono::milliseconds(1);
		file << milliseconds_since_epoch <<" = " << x << " " << y << endl;
		file.close();
	}
}
