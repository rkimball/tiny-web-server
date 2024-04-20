// BEGIN: http_client_test.cpp
#include <gtest/gtest.h>
#include <curl/curl.h>

// Mock function to simulate the response from the server
size_t mockWriteCallback(void* contents, size_t size, size_t nmemb, std::string* response) {
    size_t totalSize = size * nmemb;
    response->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

// Test case for the HTTP client
TEST(HttpClientTest, IssueRequest) {
    // Initialize the CURL library
    curl_global_init(CURL_GLOBAL_DEFAULT);

    // Create a CURL handle
    CURL* curl = curl_easy_init();
    ASSERT_TRUE(curl != nullptr);

    // Set the URL to the desired endpoint
    curl_easy_setopt(curl, CURLOPT_URL, "https://api.example.com/endpoint");

    // Set the write callback function to capture the response
    std::string response;
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, mockWriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    // Issue the request
    CURLcode res = curl_easy_perform(curl);
    ASSERT_EQ(res, CURLE_OK);

    // Check the response
    ASSERT_FALSE(response.empty());

    // Cleanup
    curl_easy_cleanup(curl);
    curl_global_cleanup();
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
// END: http_client_test.cpp