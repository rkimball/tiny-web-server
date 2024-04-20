#include <iostream>
#include <curl/curl.h>
#include <gtest/gtest.h>

// Callback function to handle the response
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* response) {
    size_t totalSize = size * nmemb;
    response->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

TEST(client, basic) {
    CURL* curl = curl_easy_init();
    if (curl) {
        // Set the URL to send the request to
        curl_easy_setopt(curl, CURLOPT_URL, "http://example.com");

        // Set the callback function to handle the response
        std::string response;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        // Perform the request
        CURLcode res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
            // Request succeeded, handle the response
            std::cout << "Response: " << response << std::endl;
        } else {
            // Request failed, handle the error
            std::cerr << "Request failed: " << curl_easy_strerror(res) << std::endl;
        }

        // Clean up
        curl_easy_cleanup(curl);
    }
}
