import matplotlib.pyplot as plt

# Draw multiple points.
def draw_multiple_points():

#	rest = True
	rest = False
	
#	up=True	
	up=False

	down=True
#	down=False
	
#	left=True
	left=False
	
#	right=True
	right=False
	
#	unknown=True
	unknown=False

	if rest:
		# x axis value list.
		x_number_list = [474,514]

		# y axis value list.
		y_number_list = [491,531]


		# Draw point based on above x, y axis values.
		plt.scatter(x_number_list, y_number_list, s=10)

	if unknown:
		x = [1024,1025]
		y=[1024,1025]
		plt.scatter(x, y, s=10)
			
	if up:
		x=[244,744]
		y=[0,50]
		plt.scatter(x, y, s=10)
		
	if down:
		x=[244,744]
		y=[973,0]
		plt.scatter(x, y, s=10)
		
	if left:
		x=[973,1023]
		y=[261,761]
		plt.scatter(x, y, s=10)
	
	if right:
		x=[0,50]
		y=[261,761]
		plt.scatter(x, y, s=10)
		
    # Set chart title.
	plt.title("Extract Number Root ")

	plt.xlim(-5, 1030)
	plt.ylim(-5, 1030)
    # Set x, y label text.
	plt.xlabel("Number")
	plt.ylabel("Extract Root of Number")
	plt.show()

if __name__ == '__main__':
	draw_multiple_points()
