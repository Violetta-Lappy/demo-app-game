#include "webview.h"

#include <chrono>
#include <string>
#include <thread>

constexpr const auto html =
R"html(<button id="increment">Tap me</button>
<div>You tapped <span id="count">0</span> time(s).</div>
<button id="compute">Compute</button>
<div>Result of computation: <span id="compute-result">0</span></div>
<div>Hello World.</div>
<p>
<!-- Three -->
	<section id="three" class="main style1 special">
		<div class="container">

			<header class="major">
				<h2>Collaboration Game Projects</h2>
			</header>
			<p>A list of game projects that I team up with others</p>

			<div class="row gtr-150">
				
				<div class="col-4 col-12-medium">
					<span class="image fit"><img src="images/image-game-apexdungeon.png" alt="" /></span>										
					<h3><a href="https://hoanglongplanner.itch.io/apex-dungeon">Apex Dungeon</a></h3>
					<p>
						3D Action Roguelike Procedural Dungeon Game.
					</p>					
				</div>				

				<div class="col-4 col-12-medium">
					<span class="image fit"><img src="images/image-game-thelaststarlord.jpg" alt="" /></span>
					<h3><a href="https://hoanglongplanner.itch.io/buv-gamejam-may-2022">The Last Star Lord</a></h3>
					<p>
						2D Platformer Game made in 48-hours game jam event.
					</p>					
				</div>				

			</div>

		</div>
	</section>
						
<script>
  const [incrementElement, countElement, computeElement, computeResultElement] =
    document.querySelectorAll("#increment, #count, #compute, #compute-result");
  document.addEventListener("DOMContentLoaded", () => {
    incrementElement.addEventListener("click", () => {
      window.increment().then(result => {
        countElement.textContent = result.count;
      });
    });
    computeElement.addEventListener("click", () => {
      computeElement.disabled = true;
      window.compute(6, 7).then(result => {
        computeResultElement.textContent = result;
        computeElement.disabled = false;
      });
    });
  });
</script>)html";

int main() {
    unsigned int count = 0;
    webview::webview w(false, nullptr);
    w.set_title("Violetta Lappy Example");
    w.set_size(480, 320, WEBVIEW_HINT_NONE);

    // A binding that increments a value and immediately returns the new value.
    w.bind("increment", [&](const std::string& /*req*/) -> std::string {
        auto count_string = std::to_string(++count);
        return "{\"count\": " + count_string + "}";
        });

    // An binding that creates a new thread and returns the result at a later time.
    w.bind(
        "compute",
        [&](const std::string& seq, const std::string& req, void* /*arg*/) {
            // Create a thread and forget about it for the sake of simplicity.
            std::thread([&, seq, req] {
                // Simulate load.
                std::this_thread::sleep_for(std::chrono::seconds(1));
                // json_parse() is an implementation detail and is only used here
                // to provide a working example.
                auto left = std::stoll(webview::detail::json_parse(req, "", 0));
                auto right = std::stoll(webview::detail::json_parse(req, "", 1));
                auto result = std::to_string(left * right);
                w.resolve(seq, 0, result);
                }).detach();
        },
        nullptr);

    w.set_html(html);

    //w.navigate("https://hoanglongplanner.github.io/");

    w.run();

    return 0;
}