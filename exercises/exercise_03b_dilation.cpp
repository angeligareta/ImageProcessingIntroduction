#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "../utils/utils.hpp"

/**
 * Comparator between two images
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char **argv) {
    const cv::String arguments =
            "{help h usage ? |      | print this message   }"
            "{@size          |  1   | exercises value     }"
            "{@input_image   |      | input image   }"
            "{@output_image  |      | output image }";

    cv::CommandLineParser parser(argc, argv, arguments);
    if (parser.has("help")) {
        parser.printMessage();
        return 0;
    }

    int size = parser.get<int>(0);
    cv::String input_path = parser.get<cv::String>(1);
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

    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT,
            cv::Size(2 * size + 1, 2 * size + 1));

    cv::Mat output = Utils::dilate(input, kernel);

    namedWindow("Output Image", cv::WINDOW_AUTOSIZE);
    imshow("Output Image", output);
    cv::imwrite(output_path, output);

    // cv::Mat expected_output = input.clone();
    // cv::dilate(input, expected_output, kernel);
    // cv::imwrite("./data/letter_dilated_opencv.png", expected_output);

    cv::waitKey(0);

    return 0;
}
