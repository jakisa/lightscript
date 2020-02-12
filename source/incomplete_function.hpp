#ifndef incomplete_function_hpp
#define incomplete_function_hpp

#include "tokens.hpp"
#include "types.hpp"
#include <deque>
#include <functional>

namespace stork {
	class compiler_context;
	class runtime_context;
	class tokens_iterator;
	using function = std::function<void(runtime_context&)>;

	class incomplete_function {
	private:
		std::deque<token> _tokens;
		size_t _index;
		std::vector<std::string> _params;
		type_handle _ft;
	public:
		incomplete_function(compiler_context& ctx, tokens_iterator& it);
		
		size_t index() const;
		
		function compile(compiler_context& ctx);
	};
}

#endif /* incomplete_function_hpp */