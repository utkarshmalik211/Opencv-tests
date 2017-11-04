// include opencv
#include <cv.h>
#include <highgui.h>
#include <stdio.h>

void main(int argc, char *argv[]){
        int height,width,step,channels;
        uchar *data;

        IplImage* src = cvLoadImage(argv[1], CV_LOAD_IMAGE_GRAYSCALE);

        IplImage* cc_img = cvCreateImage( cvGetSize(src), src->depth, 3 );
        cvSetZero(cc_img);
        CvScalar(ext_color);

        CvMemStorage *mem;
        mem = cvCreateMemStorage(0);
        CvSeq *contours = 0;

        // edges returned by Canny might have small gaps between them, which causes some problems during contour detection
        // Simplest way to solve this s to "dilate" the image.
        double t = cvThreshold(src,src,90,255,0);
        height    = src->height;
        width     = src->width;
        step      = src->widthStep;
        channels  = src->nChannels;
        data      = (uchar *)src->imageData;
        printf("Coverting image to a %dx%d...Done\n",height,width);
        int b[28*28],c[28][28];
        // invert the image
        printf("Inverting image...Done\n");
        for(int i=0; i<height; i++) {
                for(int j=0; j<width; j++) {
                        for(int k=0; k<channels; k++) {
                                data[i*step+j*channels+k]=255-data[i*step+j*channels+k];
                        }
                }
        }
        //cvCanny(src, src, 10, 50, 3);
        cvShowImage("Tutorial", src);
        cvWaitKey(0);

        int n = cvFindContours( src, mem, &contours, sizeof(CvContour), CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE, cvPoint(0,0));
        int i=0;
        CvSeq* ptr = 0;
        CvRect rects[10];
        for (ptr = contours; ptr != NULL; ptr = ptr->h_next)
        {
                // ext_color = CV_RGB( 255, 255, 255 ); //randomly coloring different contours
                // cvDrawContours(cc_img, ptr, ext_color, CV_RGB(0,0,0), -1, CV_FILLED, 8, cvPoint(0,0));
                rects[i] =cvBoundingRect(ptr,0);
                cvRectangle(src,( rects[i]->x,rects[i]->y), rects[i]->br, CvScalar color, 2, 8, 0 )

        }

        cvShowImage("Tutorial", cc_img);
        //cvSaveImage("out.png", cc_img);xxxxxxx

        cvWaitKey(0);

}
