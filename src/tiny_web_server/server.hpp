#include <string>
#include

namespace tiny_web_server {

using request_fn = std::function<bool(
    const string &path, std::unordered_map<std::string, std::string> args)>;
class Server {
   public:
    Server(uint16_t port);
    ~Server();

    void RegisterHandler(const std::string &path, request_fn callback);

   private:
    std::unordered_map<const std::string & path, request_fn callback> registry;
}
}  // namespace tiny_web_server