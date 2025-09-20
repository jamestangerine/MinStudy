const currentVersion = "v0.0.25";

const CACHE_LIST = [
    "/MinStudy/",
    "/MinStudy/index.html",
    "/MinStudy/prog.js",
    "/MinStudy/prog.wasm",
    "/MinStudy/manifest.webmanifest",
    "/MinStudy/site.css",
];

self.addEventListener("install", (event) => {
    event.waitUntil(
        caches.open(currentVersion).then((cache) => {
            return cache.addAll(CACHE_LIST);
        })
    );
    self.skipWaiting();
});

self.addEventListener("activate", (event) => {
    event.waitUntil(
        caches.keys().then((cacheNames) => {
            return Promise.all(
                cacheNames.map((cacheName) => {
                    if (cacheName !== currentVersion) {
                        return caches.delete(cacheName);
                    }
                })
            );
        })
    );
    self.clients.claim();
});

self.addEventListener("fetch", (event) => {
    event.respondWith(
        caches.match(event.request).then((response) => {
            return response || fetch(event.request);
        })
    );
});