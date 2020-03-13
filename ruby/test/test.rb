require "minitest/autorun"
require_relative '../lib/warnsdorff.rb'

class Test < Minitest::Test
	def setup
		@inst = Warnsdorff.new
		assert_equal "Hello", @inst.say_hello()
	end
end
