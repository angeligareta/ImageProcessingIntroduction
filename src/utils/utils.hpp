#include <opencv2/opencv.hpp>
#include <utility>      // std::pair, std::make_pair

class Utils {
    public:
    static cv::Mat dilate(cv::Mat image, cv::Mat kernel) {
        cv::Mat outputImage = image.clone();

        for (int i = 0; i < image.rows; ++i) {
            for (int j = 0; j < image.cols; ++j) {
                // std::cout << "(" << i << ", " << j << ") | Original: ";
                // std::cout << (int) outputImage.at<uchar>(i, j) << " | Modified: ";
                int max = getMaxMin(image, kernel, cv::Point(i, j)).first;
                
                // Check value is valid
                if (max <= 255) {
                    // std::cout << max << "\n";
                    outputImage.at<uchar>(i, j) = max;
                }
            }
        }

        return outputImage;
    }

    static cv::Mat erode(cv::Mat image, cv::Mat kernel) {
        cv::Mat outputImage = image.clone();

        for (int i = 0; i < image.rows; ++i) {
            for (int j = 0; j < image.cols; ++j) {
                int min = getMaxMin(image, kernel, cv::Point(i, j)).second;

                // Check value is valid
                if (min >= 0) {
                    outputImage.at<uchar>(i, j) = min;
                }
            }
        }

        return outputImage;
    }

    static cv::Mat opening(cv::Mat image, cv::Mat kernel) {
        cv::Mat eroded_image = erode(image, kernel);
        cv::Mat dilated_image = dilate(eroded_image, kernel);
        return dilated_image;
    }

    static cv::Mat closing(cv::Mat image, cv::Mat kernel) {
        cv::Mat dilated_image = dilate(image, kernel);
        cv::Mat eroded_image = erode(dilated_image, kernel);
        return eroded_image;
    }    

    private:

    /**
     * Returns point with max as first and min as second of the area where the kernel overlaps with the image
     * */
    static std::pair<int, int> getMaxMin(cv::Mat image, cv::Mat kernel, cv::Point origin) {
        int width = kernel.rows / 2;
        int height = kernel.cols / 2;

        // If the width is even, remove one cell to see from the right
        int oneCellWidth = (kernel.rows % 2 == 0) ? 1 : 0;
        int oneCellHeight = (kernel.cols % 2 == 0) ? 1 : 0;

        // Add limits
        int max = -1;
        int min = 256;

        for (int i = -width; i <= width - oneCellWidth; ++i) {
            int imageX = origin.x + i;

            // Check if kernel x is inside image
            if (imageX >= 0 && imageX < image.rows) {
                for (int j = -height; j <= height - oneCellHeight; ++j) {
                    // std::cout << "(" << i << ", " << j << ")";
                    int imageY = origin.y + j;

                    // Check if kernel y is inside image
                    if (imageY >= 0 && imageY < image.cols) {
                        int outputPixel = (int) image.at<uchar>(imageX, imageY);
//                        std::cout << "(" << imageX << ", " << imageY << ") =>" << outputPixel;
                        // Calculate max
                        if (outputPixel > max) {
                            max = outputPixel;
                        }

                        // Calculate min
                        if (outputPixel < min) {
                            min = outputPixel;
                        }
                    }
                }
            }
        }

        // std::cout << std::endl;

        return std::make_pair(max, min);
    }    
};