#include <stdio.h>
#include <opencv2/opencv.hpp>

/**
 * Comparator between two images
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char **argv) {
    const cv::String arguments =
            "{help h usage ? |      | print this message   }"
            "{@input_image_1   |      | image1 for sup   }"
            "{@input_image_2  |      | image2 for sup   }"
            "{@output_image  |      | output image }";

    cv::CommandLineParser parser(argc, argv, arguments);
    parser.about("Comparator app v1.0.0");
    if (parser.has("help")) {
        parser.printMessage();
        return 0;
    }

    cv::String input_path_1 = parser.get<cv::String>(0);
    cv::String input_path_2 = parser.get<cv::String>(1);
    cv::String output_path = parser.get<cv::String>(2);

    if (!parser.check()) {
        parser.printErrors();
        return 0;
    }

    cv::Mat input1 = cv::imread(input_path_1, cv::IMREAD_GRAYSCALE);
    cv::Mat input2 = cv::imread(input_path_2, cv::IMREAD_GRAYSCALE);

    if (!input1.data || !input2.data) {
        printf("No image data \n");
        return -1;
    }

    cv::Mat output = input1.clone();

    if (input1.rows == input2.rows && input1.cols == input2.cols) {
        for (int i = 0; i < input1.rows; ++i) {
            for (int j = 0; j < input1.cols; ++j) {
                output.at<uchar>(i, j) = cv::min(input1.at<uchar>(i, j), input2.at<uchar>(i, j));
            }
        }
        namedWindow("Output Image", cv::WINDOW_AUTOSIZE);
        imshow("Output Image", output);
        cv::waitKey(0);
    }
    else {
        std::cout << "Size of the input images does not match \n";
    }


    return 0;
}
