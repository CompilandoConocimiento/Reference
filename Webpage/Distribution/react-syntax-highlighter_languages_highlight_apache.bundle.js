(window["webpackJsonp"] = window["webpackJsonp"] || []).push([["react-syntax-highlighter_languages_highlight_apache"],{

/***/ "./node_modules/react-syntax-highlighter/node_modules/highlight.js/lib/languages/apache.js":
/*!*************************************************************************************************!*\
  !*** ./node_modules/react-syntax-highlighter/node_modules/highlight.js/lib/languages/apache.js ***!
  \*************************************************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

eval("module.exports = function(hljs) {\n  var NUMBER = {className: 'number', begin: '[\\\\$%]\\\\d+'};\n  return {\n    aliases: ['apacheconf'],\n    case_insensitive: true,\n    contains: [\n      hljs.HASH_COMMENT_MODE,\n      {className: 'section', begin: '</?', end: '>'},\n      {\n        className: 'attribute',\n        begin: /\\w+/,\n        relevance: 0,\n        // keywords aren’t needed for highlighting per se, they only boost relevance\n        // for a very generally defined mode (starts with a word, ends with line-end\n        keywords: {\n          nomarkup:\n            'order deny allow setenv rewriterule rewriteengine rewritecond documentroot ' +\n            'sethandler errordocument loadmodule options header listen serverroot ' +\n            'servername'\n        },\n        starts: {\n          end: /$/,\n          relevance: 0,\n          keywords: {\n            literal: 'on off all'\n          },\n          contains: [\n            {\n              className: 'meta',\n              begin: '\\\\s\\\\[', end: '\\\\]$'\n            },\n            {\n              className: 'variable',\n              begin: '[\\\\$%]\\\\{', end: '\\\\}',\n              contains: ['self', NUMBER]\n            },\n            NUMBER,\n            hljs.QUOTE_STRING_MODE\n          ]\n        }\n      }\n    ],\n    illegal: /\\S/\n  };\n};//# sourceURL=[module]\n//# sourceMappingURL=data:application/json;charset=utf-8;base64,eyJ2ZXJzaW9uIjozLCJmaWxlIjoiLi9ub2RlX21vZHVsZXMvcmVhY3Qtc3ludGF4LWhpZ2hsaWdodGVyL25vZGVfbW9kdWxlcy9oaWdobGlnaHQuanMvbGliL2xhbmd1YWdlcy9hcGFjaGUuanMuanMiLCJzb3VyY2VzIjpbIndlYnBhY2s6Ly8vLi9ub2RlX21vZHVsZXMvcmVhY3Qtc3ludGF4LWhpZ2hsaWdodGVyL25vZGVfbW9kdWxlcy9oaWdobGlnaHQuanMvbGliL2xhbmd1YWdlcy9hcGFjaGUuanM/NGMxYiJdLCJzb3VyY2VzQ29udGVudCI6WyJtb2R1bGUuZXhwb3J0cyA9IGZ1bmN0aW9uKGhsanMpIHtcbiAgdmFyIE5VTUJFUiA9IHtjbGFzc05hbWU6ICdudW1iZXInLCBiZWdpbjogJ1tcXFxcJCVdXFxcXGQrJ307XG4gIHJldHVybiB7XG4gICAgYWxpYXNlczogWydhcGFjaGVjb25mJ10sXG4gICAgY2FzZV9pbnNlbnNpdGl2ZTogdHJ1ZSxcbiAgICBjb250YWluczogW1xuICAgICAgaGxqcy5IQVNIX0NPTU1FTlRfTU9ERSxcbiAgICAgIHtjbGFzc05hbWU6ICdzZWN0aW9uJywgYmVnaW46ICc8Lz8nLCBlbmQ6ICc+J30sXG4gICAgICB7XG4gICAgICAgIGNsYXNzTmFtZTogJ2F0dHJpYnV0ZScsXG4gICAgICAgIGJlZ2luOiAvXFx3Ky8sXG4gICAgICAgIHJlbGV2YW5jZTogMCxcbiAgICAgICAgLy8ga2V5d29yZHMgYXJlbuKAmXQgbmVlZGVkIGZvciBoaWdobGlnaHRpbmcgcGVyIHNlLCB0aGV5IG9ubHkgYm9vc3QgcmVsZXZhbmNlXG4gICAgICAgIC8vIGZvciBhIHZlcnkgZ2VuZXJhbGx5IGRlZmluZWQgbW9kZSAoc3RhcnRzIHdpdGggYSB3b3JkLCBlbmRzIHdpdGggbGluZS1lbmRcbiAgICAgICAga2V5d29yZHM6IHtcbiAgICAgICAgICBub21hcmt1cDpcbiAgICAgICAgICAgICdvcmRlciBkZW55IGFsbG93IHNldGVudiByZXdyaXRlcnVsZSByZXdyaXRlZW5naW5lIHJld3JpdGVjb25kIGRvY3VtZW50cm9vdCAnICtcbiAgICAgICAgICAgICdzZXRoYW5kbGVyIGVycm9yZG9jdW1lbnQgbG9hZG1vZHVsZSBvcHRpb25zIGhlYWRlciBsaXN0ZW4gc2VydmVycm9vdCAnICtcbiAgICAgICAgICAgICdzZXJ2ZXJuYW1lJ1xuICAgICAgICB9LFxuICAgICAgICBzdGFydHM6IHtcbiAgICAgICAgICBlbmQ6IC8kLyxcbiAgICAgICAgICByZWxldmFuY2U6IDAsXG4gICAgICAgICAga2V5d29yZHM6IHtcbiAgICAgICAgICAgIGxpdGVyYWw6ICdvbiBvZmYgYWxsJ1xuICAgICAgICAgIH0sXG4gICAgICAgICAgY29udGFpbnM6IFtcbiAgICAgICAgICAgIHtcbiAgICAgICAgICAgICAgY2xhc3NOYW1lOiAnbWV0YScsXG4gICAgICAgICAgICAgIGJlZ2luOiAnXFxcXHNcXFxcWycsIGVuZDogJ1xcXFxdJCdcbiAgICAgICAgICAgIH0sXG4gICAgICAgICAgICB7XG4gICAgICAgICAgICAgIGNsYXNzTmFtZTogJ3ZhcmlhYmxlJyxcbiAgICAgICAgICAgICAgYmVnaW46ICdbXFxcXCQlXVxcXFx7JywgZW5kOiAnXFxcXH0nLFxuICAgICAgICAgICAgICBjb250YWluczogWydzZWxmJywgTlVNQkVSXVxuICAgICAgICAgICAgfSxcbiAgICAgICAgICAgIE5VTUJFUixcbiAgICAgICAgICAgIGhsanMuUVVPVEVfU1RSSU5HX01PREVcbiAgICAgICAgICBdXG4gICAgICAgIH1cbiAgICAgIH1cbiAgICBdLFxuICAgIGlsbGVnYWw6IC9cXFMvXG4gIH07XG59OyJdLCJtYXBwaW5ncyI6IkFBQUE7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBIiwic291cmNlUm9vdCI6IiJ9\n//# sourceURL=webpack-internal:///./node_modules/react-syntax-highlighter/node_modules/highlight.js/lib/languages/apache.js\n");

/***/ })

}]);