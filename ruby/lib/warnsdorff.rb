class Warnsdorff
	
	def check_limit(x,y)
		return (x>=0 && x<@size && y>= 0 && y<@size)
	end

	def check_completion()
		return (@visited.length() == @size*@size)
		return false
	end

	def print_moves()
		(0..@size-1).each do |i|
			(0..@size-1).each do |j|
				print @move[i][j].to_s+" "
			end
			puts '\n'
		end
	end

	def get_node_degree(p,q)
		count = 0
		(0..@x.length()-1).each do |i|
			count = count + 1 if (check_limit(p+@x[i],q+@y[i]) && !@visited.include?((p+@x[i])*@size + q+@y[i]))
		end
		return count
	end

	def check_moves(p,q,count)
		return true if check_completion()
		minx = miny=-1 
		min=1000
		(0..@x.length()-1).each do |i|
			if(check_limit(p+@x[i],q+@y[i]) && !@visited.include?((p+@x[i])*@size + q+@y[i]))
				temp = get_node_degree(p+@x[i],q+@y[i])
				if(temp<min)
					min =temp
					minx = p+@x[i]
					miny = q+@y[i]
				end
			end
		end
		 
		if (minx!=-1)
			@visited.push(@size*minx+miny)
			@move[minx][miny] = count+1
			return check_moves(minx,miny,count+1)
		end
		return false   
	end

	def initialize(input_stream = nil, output_stream = nil)
		@visited = []
		@size = 10
		@move = Array.new(@size) { Array.new(@size)}

		@x = [-2,+2,-2,+2,+3,-3,0,0]
		@y = [-2,+2,+2,-2,0,0,+3,-3]

		puts 'Enter the coords(space seperated!): ' if output_stream.nil?
		output_stream.puts 'Enter the coords(space seperated!): ' unless output_stream.nil?

		@start_coords = gets.chomp.split(' ')  if input_stream.nil?
		@start_coords = input_stream.gets.chomp.split(' ') unless input_stream.nil?

		@start_coords = @start_coords.map {|coord| coord.to_i}
		p = @start_coords[0]
		q = @start_coords[1]
		@move[p][q] = 1
		@visited.push(p*@size+q)
		if check_moves(p,q,1)
			print_moves()
		else
			puts 'Not possible!(run this case from console,irb for all the data)'
		end
	end

end

Warnsdorff.new
