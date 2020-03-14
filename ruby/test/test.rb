require "minitest/autorun"
require_relative '../lib/warnsdorff.rb'

class Test < Minitest::Test
	def setup
		@input_stream = StringIO.new("0 3")
    	@output_stream = StringIO.new
		@inst = Warnsdorff.new(@input_stream,@output_stream)
	end
	def check_visited_length
		p @inst.visited	
		assert_equal 100,@inst.visited.length()
	end
	# def initialize()
	# 	puts "dsadsa"
	# 	setup()
	# 	check_visited_length()
	# end
end
