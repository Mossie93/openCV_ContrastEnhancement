Simple image contrast enhancement project realized with openCV.

Takes in 4 parameters:
<input_img_file_name>		Name of file with input image.
<output_img_file_name>		Name of file where output image should be saved.
<primary_enhancement_factor>	Central element of mask.
<secondary_enhancement_factor>	Lateral element of mask.

Mask matrix construction method:
 | 0	se 		0  |	
 | se 	pe 		se |
 | 0	se		0 _|

Coded by: Rafal Mossakowski
Language: C++
Based on: http://docs.opencv.org/doc/tutorials/core/mat-mask-operations/mat-mask-operations.html