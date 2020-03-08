#include <stdio.h>
#include <opencv2/opencv.hpp>

/**
 * Threshold with a value
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char **argv) {
    const cv::String arguments =
            "{help h usage ? |      | print this message   }"
            "{@input_image   |      | image1 for compare   }"
            "{@value         |      | exercises value      }"
            "{@output_image  |      | image2 for compare   }";

    cv::CommandLineParser parser(argc, argv, arguments);
    parser.about("Threshold app v1.0.0");
    if (parser.has("help")) {
        parser.printMessage();
        return 0;
    }

    cv::String input_path = parser.get<cv::String>(0);
    int value = parser.get<int>(1);
    cv::String output_path = parser.get<cv::String>(2);

    if (!parser.check()) {
        parser.printErrors();
        return 0;
    }

    cv::Mat input = cv::imread(input_path, cv::IMREAD_GRAYSCALE);

    if (!input.data) {
        printf("No image data \n");
        return -1;
    }

    namedWindow("Input Image", cv::WINDOW_AUTOSIZE);
    imshow("Input Image", input);

    cv::Mat output = input.clone();

    for (int i = 0; i < input.rows; ++i) {
        for (int j = 0; j < input.cols; ++j) {
            int pixelValue = (int) output.at<uchar>(i, j);
            if (pixelValue < value) {
                output.at<uchar>(i, j) = 0;
            } else {
                output.at<uchar>(i, j) = 255;
            }
        }
    }

    namedWindow("Output Image", cv::WINDOW_AUTOSIZE);
    imshow("Output Image", output);

    cv::imwrite(output_path, output);

    cv::waitKey(0);

    return 0;
}
