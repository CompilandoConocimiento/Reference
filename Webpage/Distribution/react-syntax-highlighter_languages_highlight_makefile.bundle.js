(window["webpackJsonp"] = window["webpackJsonp"] || []).push([["react-syntax-highlighter_languages_highlight_makefile"],{

/***/ "./node_modules/react-syntax-highlighter/node_modules/highlight.js/lib/languages/makefile.js":
/*!***************************************************************************************************!*\
  !*** ./node_modules/react-syntax-highlighter/node_modules/highlight.js/lib/languages/makefile.js ***!
  \***************************************************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

eval("module.exports = function(hljs) {\n  /* Variables: simple (eg $(var)) and special (eg $@) */\n  var VARIABLE = {\n    className: 'variable',\n    variants: [\n      {\n        begin: '\\\\$\\\\(' + hljs.UNDERSCORE_IDENT_RE + '\\\\)',\n        contains: [hljs.BACKSLASH_ESCAPE],\n      },\n      {\n        begin: /\\$[@%<?\\^\\+\\*]/\n      },\n    ]\n  };\n  /* Quoted string with variables inside */\n  var QUOTE_STRING = {\n    className: 'string',\n    begin: /\"/, end: /\"/,\n    contains: [\n      hljs.BACKSLASH_ESCAPE,\n      VARIABLE,\n    ]\n  };\n  /* Function: $(func arg,...) */\n  var FUNC = {\n    className: 'variable',\n    begin: /\\$\\([\\w-]+\\s/, end: /\\)/,\n    keywords: {\n      built_in:\n        'subst patsubst strip findstring filter filter-out sort ' +\n        'word wordlist firstword lastword dir notdir suffix basename ' +\n        'addsuffix addprefix join wildcard realpath abspath error warning ' +\n        'shell origin flavor foreach if or and call eval file value',\n    },\n    contains: [\n      VARIABLE,\n    ]\n  };\n  /* Variable assignment */\n  var VAR_ASSIG = {\n    begin: '^' + hljs.UNDERSCORE_IDENT_RE + '\\\\s*[:+?]?=',\n    illegal: '\\\\n',\n    returnBegin: true,\n    contains: [\n      {\n        begin: '^' + hljs.UNDERSCORE_IDENT_RE, end: '[:+?]?=',\n        excludeEnd: true,\n      }\n    ]\n  };\n  /* Meta targets (.PHONY) */\n  var META = {\n    className: 'meta',\n    begin: /^\\.PHONY:/, end: /$/,\n    keywords: {'meta-keyword': '.PHONY'},\n    lexemes: /[\\.\\w]+/\n  };\n  /* Targets */\n  var TARGET = {\n    className: 'section',\n    begin: /^[^\\s]+:/, end: /$/,\n    contains: [VARIABLE,]\n  };\n  return {\n    aliases: ['mk', 'mak'],\n    keywords:\n      'define endef undefine ifdef ifndef ifeq ifneq else endif ' +\n      'include -include sinclude override export unexport private vpath',\n    lexemes: /[\\w-]+/,\n    contains: [\n      hljs.HASH_COMMENT_MODE,\n      VARIABLE,\n      QUOTE_STRING,\n      FUNC,\n      VAR_ASSIG,\n      META,\n      TARGET,\n    ]\n  };\n};//# sourceURL=[module]\n//# sourceMappingURL=data:application/json;charset=utf-8;base64,eyJ2ZXJzaW9uIjozLCJmaWxlIjoiLi9ub2RlX21vZHVsZXMvcmVhY3Qtc3ludGF4LWhpZ2hsaWdodGVyL25vZGVfbW9kdWxlcy9oaWdobGlnaHQuanMvbGliL2xhbmd1YWdlcy9tYWtlZmlsZS5qcy5qcyIsInNvdXJjZXMiOlsid2VicGFjazovLy8uL25vZGVfbW9kdWxlcy9yZWFjdC1zeW50YXgtaGlnaGxpZ2h0ZXIvbm9kZV9tb2R1bGVzL2hpZ2hsaWdodC5qcy9saWIvbGFuZ3VhZ2VzL21ha2VmaWxlLmpzPzUxODUiXSwic291cmNlc0NvbnRlbnQiOlsibW9kdWxlLmV4cG9ydHMgPSBmdW5jdGlvbihobGpzKSB7XG4gIC8qIFZhcmlhYmxlczogc2ltcGxlIChlZyAkKHZhcikpIGFuZCBzcGVjaWFsIChlZyAkQCkgKi9cbiAgdmFyIFZBUklBQkxFID0ge1xuICAgIGNsYXNzTmFtZTogJ3ZhcmlhYmxlJyxcbiAgICB2YXJpYW50czogW1xuICAgICAge1xuICAgICAgICBiZWdpbjogJ1xcXFwkXFxcXCgnICsgaGxqcy5VTkRFUlNDT1JFX0lERU5UX1JFICsgJ1xcXFwpJyxcbiAgICAgICAgY29udGFpbnM6IFtobGpzLkJBQ0tTTEFTSF9FU0NBUEVdLFxuICAgICAgfSxcbiAgICAgIHtcbiAgICAgICAgYmVnaW46IC9cXCRbQCU8P1xcXlxcK1xcKl0vXG4gICAgICB9LFxuICAgIF1cbiAgfTtcbiAgLyogUXVvdGVkIHN0cmluZyB3aXRoIHZhcmlhYmxlcyBpbnNpZGUgKi9cbiAgdmFyIFFVT1RFX1NUUklORyA9IHtcbiAgICBjbGFzc05hbWU6ICdzdHJpbmcnLFxuICAgIGJlZ2luOiAvXCIvLCBlbmQ6IC9cIi8sXG4gICAgY29udGFpbnM6IFtcbiAgICAgIGhsanMuQkFDS1NMQVNIX0VTQ0FQRSxcbiAgICAgIFZBUklBQkxFLFxuICAgIF1cbiAgfTtcbiAgLyogRnVuY3Rpb246ICQoZnVuYyBhcmcsLi4uKSAqL1xuICB2YXIgRlVOQyA9IHtcbiAgICBjbGFzc05hbWU6ICd2YXJpYWJsZScsXG4gICAgYmVnaW46IC9cXCRcXChbXFx3LV0rXFxzLywgZW5kOiAvXFwpLyxcbiAgICBrZXl3b3Jkczoge1xuICAgICAgYnVpbHRfaW46XG4gICAgICAgICdzdWJzdCBwYXRzdWJzdCBzdHJpcCBmaW5kc3RyaW5nIGZpbHRlciBmaWx0ZXItb3V0IHNvcnQgJyArXG4gICAgICAgICd3b3JkIHdvcmRsaXN0IGZpcnN0d29yZCBsYXN0d29yZCBkaXIgbm90ZGlyIHN1ZmZpeCBiYXNlbmFtZSAnICtcbiAgICAgICAgJ2FkZHN1ZmZpeCBhZGRwcmVmaXggam9pbiB3aWxkY2FyZCByZWFscGF0aCBhYnNwYXRoIGVycm9yIHdhcm5pbmcgJyArXG4gICAgICAgICdzaGVsbCBvcmlnaW4gZmxhdm9yIGZvcmVhY2ggaWYgb3IgYW5kIGNhbGwgZXZhbCBmaWxlIHZhbHVlJyxcbiAgICB9LFxuICAgIGNvbnRhaW5zOiBbXG4gICAgICBWQVJJQUJMRSxcbiAgICBdXG4gIH07XG4gIC8qIFZhcmlhYmxlIGFzc2lnbm1lbnQgKi9cbiAgdmFyIFZBUl9BU1NJRyA9IHtcbiAgICBiZWdpbjogJ14nICsgaGxqcy5VTkRFUlNDT1JFX0lERU5UX1JFICsgJ1xcXFxzKls6Kz9dPz0nLFxuICAgIGlsbGVnYWw6ICdcXFxcbicsXG4gICAgcmV0dXJuQmVnaW46IHRydWUsXG4gICAgY29udGFpbnM6IFtcbiAgICAgIHtcbiAgICAgICAgYmVnaW46ICdeJyArIGhsanMuVU5ERVJTQ09SRV9JREVOVF9SRSwgZW5kOiAnWzorP10/PScsXG4gICAgICAgIGV4Y2x1ZGVFbmQ6IHRydWUsXG4gICAgICB9XG4gICAgXVxuICB9O1xuICAvKiBNZXRhIHRhcmdldHMgKC5QSE9OWSkgKi9cbiAgdmFyIE1FVEEgPSB7XG4gICAgY2xhc3NOYW1lOiAnbWV0YScsXG4gICAgYmVnaW46IC9eXFwuUEhPTlk6LywgZW5kOiAvJC8sXG4gICAga2V5d29yZHM6IHsnbWV0YS1rZXl3b3JkJzogJy5QSE9OWSd9LFxuICAgIGxleGVtZXM6IC9bXFwuXFx3XSsvXG4gIH07XG4gIC8qIFRhcmdldHMgKi9cbiAgdmFyIFRBUkdFVCA9IHtcbiAgICBjbGFzc05hbWU6ICdzZWN0aW9uJyxcbiAgICBiZWdpbjogL15bXlxcc10rOi8sIGVuZDogLyQvLFxuICAgIGNvbnRhaW5zOiBbVkFSSUFCTEUsXVxuICB9O1xuICByZXR1cm4ge1xuICAgIGFsaWFzZXM6IFsnbWsnLCAnbWFrJ10sXG4gICAga2V5d29yZHM6XG4gICAgICAnZGVmaW5lIGVuZGVmIHVuZGVmaW5lIGlmZGVmIGlmbmRlZiBpZmVxIGlmbmVxIGVsc2UgZW5kaWYgJyArXG4gICAgICAnaW5jbHVkZSAtaW5jbHVkZSBzaW5jbHVkZSBvdmVycmlkZSBleHBvcnQgdW5leHBvcnQgcHJpdmF0ZSB2cGF0aCcsXG4gICAgbGV4ZW1lczogL1tcXHctXSsvLFxuICAgIGNvbnRhaW5zOiBbXG4gICAgICBobGpzLkhBU0hfQ09NTUVOVF9NT0RFLFxuICAgICAgVkFSSUFCTEUsXG4gICAgICBRVU9URV9TVFJJTkcsXG4gICAgICBGVU5DLFxuICAgICAgVkFSX0FTU0lHLFxuICAgICAgTUVUQSxcbiAgICAgIFRBUkdFVCxcbiAgICBdXG4gIH07XG59OyJdLCJtYXBwaW5ncyI6IkFBQUE7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQSIsInNvdXJjZVJvb3QiOiIifQ==\n//# sourceURL=webpack-internal:///./node_modules/react-syntax-highlighter/node_modules/highlight.js/lib/languages/makefile.js\n");

/***/ })

}]);